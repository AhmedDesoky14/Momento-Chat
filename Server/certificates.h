#pragma once
#include <string>
#include <stdexcept>
#include <memory>
#include <openssl/pem.h>
#include <openssl/x509.h>
#include <openssl/x509_vfy.h>

#include "keys.h"
#include "utils.h"
#include "conf.h"

class certificate_abstract
{
protected:
	std::string cert_path;	//certificate path
	certificate_abstract(void) = default;	//default non-parameterized constructor
	certificate_abstract(const std::string& path) : cert_path(path) {}	//abstract class constructor
	virtual ~certificate_abstract(void) = default; //virtual default destructor
public:
	virtual void SignCertificate(std::shared_ptr<openssl_key_base>) = 0;	//sign any certificate
	virtual bool isCertificateSigned(std::shared_ptr<openssl_key_base>) = 0;	//verify any certificate
	virtual void Store(std::string& path) = 0;	//to store the certificate or the csr
	virtual std::vector<unsigned char> Serialize(void) = 0;	//to serialize the certificate or the csr
	inline std::string GetPath(void) const
	{
		return cert_path;
	}
};
class openssl_certificate_request_base : public certificate_abstract
{
protected:
	openssl_certificate_request_base(void) : certificate_abstract() {}	//non-stored csr
	openssl_certificate_request_base(const std::string& path) : certificate_abstract(path) {}//for both new and existing CSRs
	virtual ~openssl_certificate_request_base(void) = default;	//virtual default destructor
};

class openssl_certificate_base : public certificate_abstract
{
protected:
	std::string serial_number;
	BIGNUM* serial_bn;
	BIGNUM* GenerateSerial(void);	//non-virtual function
	openssl_certificate_base(void) : certificate_abstract() {}	//non-stored certificate
	openssl_certificate_base(const std::string& path) : certificate_abstract(path) {} //for both new and existing certs
	virtual ~openssl_certificate_base(void);	//virtual destructor to free serial_bn resources
	inline std::string GetSerial(void) const
	{
		return serial_number;
	}
};

class X509_CSR : public openssl_certificate_request_base
{
private:
	X509_REQ* csr;
public:
	X509_CSR(std::vector<std::string>& subject, std::shared_ptr<openssl_key_base> pubkey_ptr);	//create new csr, with new subject and new public key
	X509_CSR(const std::string& csr_pem_file);	//existed csr
	X509_CSR(const std::vector<unsigned char>& csr_data);	//existed csr from stream of data
	void SignCertificate(std::shared_ptr<openssl_key_base> privkey_ptr);	//sign csr
	bool isCertificateSigned(std::shared_ptr<openssl_key_base> pubkey_ptr);	//verify any csr
	void Store(std::string& path);	//to store the csr
	std::vector<unsigned char> Serialize(void);	//serialize the certificate
	inline X509_REQ* GetCSRRaw(void)
	{
		return csr;
	}
};

class X509_Certificate : public openssl_certificate_base
{
private:
	X509* cert;
public:
	X509_Certificate(const std::string& cert_pem_file);	//existed certificate
	X509_Certificate(const std::vector<unsigned char>& cert_data);	//existed certificate from stream of data
	X509_Certificate(X509_REQ* csr);	//CSR to sign and store it as certificate later
	X509_Certificate(X509* cert);	//to create self-signed certificate later, rarely used
	void SignCertificate(std::shared_ptr<openssl_key_base> privkey_ptr);	//sign certificate
	bool isCertificateSigned(std::shared_ptr<openssl_key_base> pubkey_ptr);	//verify any certificate
	void Store(std::string& path);	//to store the certificate
	std::vector<unsigned char> Serialize(void);	//serialize the certificate
	inline X509* GetCertificateRaw(void) const
	{
		return cert;
	}
};
class certificate_basex	//abstract class
{
protected:
	std::string cert_path;	//certificate path
	std::string serial_number;	//certificate serial number as string
	certificate_basex(const std::string& path) : cert_path(path) {} //for both new and existing certificates
	virtual ~certificate_basex(void) = default;	//virtual default destructor
	virtual BIGNUM* GenerateSerial(void)	//virtual, can be overriden
	{
		BIGNUM* bignum = BN_new();
		if (!bignum)
			throw std::runtime_error("Failed to create BIGNUM for serial number");
		if (!BN_pseudo_rand(bignum, SERIAL_NUMBER_SIZE, 0, 0))	//create 128bit random number
		{
			BN_free(bignum);	//free memory of BIGNUM
			throw std::runtime_error("Failed to generate pseudorandom serial number");
		}
		return bignum;
	}
	virtual void StoreSerial(BIGNUM* serial)	//virtual, can be overriden
	{
		char* ser_char = BN_bn2hex(serial);	//convert the BIGNUM into array of hex characters
		if (!ser_char)	//if serial read succssfully
			throw std::runtime_error("Failed to store serial number");
		serial_number = std::string(ser_char);	//storing serial number into string
		OPENSSL_free(ser_char);	//free allocated memory
		return;
	}
public:
	virtual void SignCertificate(std::shared_ptr<openssl_key_base>) = 0;
	virtual bool isCertificateSigned(std::shared_ptr<openssl_key_base>) = 0;
	inline std::string GetSerial(void) const
	{
		return serial_number;
	}
	inline std::string GetPath(void) const
	{
		return cert_path;
	}
};

class X509_certificate : public certificate_basex
{
private:
	X509* cert;
public:
	X509_certificate(const std::string store_path,std::shared_ptr<openssl_key_base> pubkey_ptr, std::shared_ptr<openssl_key_base> privkey_ptr)	: certificate_basex(store_path)//new certificate, explicit call the constructor
	{
		cert = X509_new();	//create new certificate
		if (!cert)
			throw std::runtime_error("Failed to create new certificate");
		X509_set_version(cert, 2);	//set certificate version (2 = X.509v3)
		BIGNUM* generated_serial = GenerateSerial();	//generate new serial number
		ASN1_INTEGER* serialASN1 = BN_to_ASN1_INTEGER(generated_serial, nullptr);
		if(X509_set_serialNumber(cert, serialASN1) != 1)
		//if(ASN1_INTEGER_set(X509_get_serialNumber(cert), 11))
		//if (!BN_to_ASN1_INTEGER(generated_serial, X509_get_serialNumber(cert)))	// Set the generated number as the serial
		{
			ASN1_INTEGER_free(serialASN1);	//free memory
			BN_free(generated_serial);	//free the generated number object
			X509_free(cert); //clear X509 certificate memory allocated in case of exception
			throw std::runtime_error("Failed to set serial number for the certificate");
		}
		StoreSerial(generated_serial);	//store serial number in its string variable
		X509_gmtime_adj(X509_get_notBefore(cert), 0);	//set certificate validity start date, now
		X509_gmtime_adj(X509_get_notAfter(cert), 126144000L); // set certificate validity end date, after 4 years
		//if (pubkey_ptr->isPrivate()) //if key is private key
		//{
		//	ASN1_INTEGER_free(serialASN1);	//free memory
		//	BN_free(generated_serial);	//free the generated number object in case of exception
		//	X509_free(cert);	//clear X509 certificate memory allocated in case of exception
		//	throw std::runtime_error("Invalid key for the certificate, public key should be passed");
		//}
		if (X509_set_pubkey(cert, pubkey_ptr->GetKeyRaw()) != 1)//set the given key as the public key
		{
			ASN1_INTEGER_free(serialASN1);	//free memory
			BN_free(generated_serial);	//free the generated number object in case of exception
			X509_free(cert);	//clear X509 certificate memory allocated in case of exception
			throw std::runtime_error("Failed to set the public key to the certificate");
		}
		X509_NAME* issuer_name = X509_NAME_new();
		X509_NAME* subject_name = X509_NAME_new();
		X509_NAME_add_entry_by_txt(issuer_name, "C", MBSTRING_ASC, (unsigned char*)"Egypt", -1, -1, 0);	//set country
		X509_NAME_add_entry_by_txt(issuer_name, "ST", MBSTRING_ASC, (unsigned char*)"Cairo", -1, -1, 0);//set province
		X509_NAME_add_entry_by_txt(issuer_name, "L", MBSTRING_ASC, (unsigned char*)"Gardenia", -1, -1, 0);//set town
		X509_NAME_add_entry_by_txt(issuer_name, "O", MBSTRING_ASC, (unsigned char*)"Fade-Server", -1, -1, 0);//set source
		X509_NAME_add_entry_by_txt(issuer_name, "CN", MBSTRING_ASC, (unsigned char*)"Ahmed Desoky", -1, -1, 0);//set person
		//X509_NAME_add_entry_by_txt(subject_name, "CN", MBSTRING_ASC, (unsigned char*)"Fade-Chat User", -1, -1, 0);//subject
		X509_NAME_add_entry_by_txt(subject_name, "C", MBSTRING_ASC, (unsigned char*)"Egypt", -1, -1, 0);	//set country
		X509_NAME_add_entry_by_txt(subject_name, "ST", MBSTRING_ASC, (unsigned char*)"Cairo", -1, -1, 0);//set province
		X509_NAME_add_entry_by_txt(subject_name, "L", MBSTRING_ASC, (unsigned char*)"Gardenia", -1, -1, 0);//set town
		X509_NAME_add_entry_by_txt(subject_name, "O", MBSTRING_ASC, (unsigned char*)"Fade-Server", -1, -1, 0);//set source
		X509_NAME_add_entry_by_txt(subject_name, "CN", MBSTRING_ASC, (unsigned char*)"Ahmed Desoky", -1, -1, 0);//set person
		if (X509_set_issuer_name(cert, issuer_name) != 1 || !issuer_name)
		{
			X509_NAME_free(issuer_name);	//free issuer name memory
			X509_NAME_free(subject_name);	//free subject name memory
			ASN1_INTEGER_free(serialASN1);	//free memory
			BN_free(generated_serial);	//free the generated number object in case of exception
			X509_free(cert);	//clear X509 certificate memory allocated in case of exception
			throw std::runtime_error("Failed to set issuer to the certificate");
		}
		if (X509_set_subject_name(cert, subject_name) != 1 || !subject_name)
		{
			X509_NAME_free(issuer_name);	//free issuer name memory
			X509_NAME_free(subject_name);	//free subject name memory
			ASN1_INTEGER_free(serialASN1);	//free memory
			BN_free(generated_serial);	//free the generated number object in case of exception
			X509_free(cert);	//clear X509 certificate memory allocated in case of exception
			throw std::runtime_error("Failed to set subject to the certificate");
		}
		this->SignCertificate(privkey_ptr);
		BIO* basicIO = BIO_new(BIO_s_mem());
		if (PEM_write_bio_X509(basicIO, cert) != 1)	//writing the certificate in the basicIO
		{
			X509_NAME_free(issuer_name);	//free issuer name memory
			X509_NAME_free(subject_name);	//free subject name memory
			ASN1_INTEGER_free(serialASN1);	//free memory
			BN_free(generated_serial);	//free the generated number object in case of exception
			BIO_free(basicIO);	//clear basicIO memory allocated in case of exception
			X509_free(cert);	//clear X509 certificate memory allocated in case of exception
			throw std::runtime_error("Failed to write certificate into the basicIO");
		}
		unsigned char* certData = nullptr;
		long certLength = BIO_get_mem_data(basicIO, &certData);	//get data of the certificate
		if (certData == nullptr || certLength == 0)
		{
			X509_NAME_free(issuer_name);	//free issuer name memory
			X509_NAME_free(subject_name);	//free subject name memory
			ASN1_INTEGER_free(serialASN1);	//free memory
			BN_free(generated_serial);	//free the generated number object in case of exception
			BIO_free(basicIO);	//clear basicIO memory allocated in case of exception
			X509_free(cert);	//clear X509 certificate memory allocated in case of exception
			throw std::runtime_error("Failed to write certificate into its file");
		}
		std::vector<unsigned char> cert_vect(certData, certData + certLength);
		try //try to write the certificate to the file. "file::write_binary" may throw an exception
		{
			file cert_file(store_path);
			cert_file.write_binary(cert_vect);	//store certificate data in the file
		}
		catch (...)	//catch the exception and free resources first
		{
			X509_NAME_free(issuer_name);	//free issuer name memory
			X509_NAME_free(subject_name);	//free subject name memory
			ASN1_INTEGER_free(serialASN1);	//free memory
			BN_free(generated_serial);	//free the generated number object in case of exception
			BIO_free(basicIO);	//clear basicIO memory allocated in case of exception
			X509_free(cert);	//clear X509 certificate memory allocated in case of exception
			throw;	//rethrow the exception
		}
		X509_NAME_free(issuer_name);	//free issuer name memory
		X509_NAME_free(subject_name);	//free subject name memory
		ASN1_INTEGER_free(serialASN1);	//free memory
		BN_free(generated_serial);	//free the generated number object after use
		BIO_free(basicIO);	//clear basicIO memory allocated after use
	}
	X509_certificate(const std::string& cert_pem_file) : certificate_basex(cert_pem_file) //already existed certificate, explicit call the constructor
	{
		file cert_file(cert_pem_file);
		std::vector<unsigned char> cert_vect = cert_file.read_binary();	//read certificate from its file
		BIO* basicIO = BIO_new_mem_buf(cert_vect.data(), cert_vect.size());
		cert = PEM_read_bio_X509(basicIO, nullptr, nullptr, nullptr);
		if (!cert)	//failed to read the certificate
		{
			X509_free(cert);	//clear X509 certificate memory allocated in case of exception
			BIO_free(basicIO);	//clear basicIO memory allocated after use
			throw std::runtime_error("Invalid load the certificate from its pem file");
		}
		ASN1_INTEGER* serialnum = X509_get_serialNumber(cert);	//extracting the serial number
		BIGNUM* serial_bignum = ASN1_INTEGER_to_BN(serialnum, nullptr);
		StoreSerial(serial_bignum);	//store the serial number to its string variable
		BN_free(serial_bignum);	//free the generated number object after use
		BIO_free(basicIO);	//clear basicIO memory allocated after use
	}
	~X509_certificate(void)
	{
		X509_free(cert);	//clear X509 certificate memory allocated after use
	}
	void SignCertificate(std::shared_ptr<openssl_key_base> CA_private_key)	//for server software only, deleted for other
	{
		if (!CA_private_key->isPrivate())	//if its not the private
			throw std::runtime_error("Failed to sign X.509 certificate, Invalid key");
		//sign the certificate using the CA's private key (server) and by SHA256 algorithm
		if (!X509_sign(cert, CA_private_key->GetKeyRaw(), EVP_sha256()))
			throw std::runtime_error("Failed to sign X.509 certificate");
	}
	bool isCertificateSigned(std::shared_ptr<openssl_key_base> CA_public_key)
	{
		if (CA_public_key->isPrivate())	//if its not the public
			throw std::runtime_error("Failed to verify X.509 certificate, Invalid key");
		if (!X509_verify(cert, CA_public_key->GetKeyRaw()))	//if certificate is not signed
			return false;
		return true;
	}
};

//class server_certificate : public X509_certificate
//{
//	server_certificate()
//};