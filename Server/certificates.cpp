#include "certificates.h"

BIGNUM* openssl_certificate_base::GenerateSerial(void)
{
	serial_bn = BN_new();
	if (!serial_bn)
		throw std::runtime_error("Failed to create BIGNUM for serial number");
	if (!BN_pseudo_rand(serial_bn, SERIAL_NUMBER_SIZE, 0, 0))	//create 128bit random number
	{
		BN_free(serial_bn);	//free memory of BIGNUM
		throw std::runtime_error("Failed to generate pseudorandom serial number");
	}
	char* ser_char = BN_bn2hex(serial_bn);	//convert the BIGNUM into array of hex characters
	if (!ser_char)	//if serial read succssfully
		throw std::runtime_error("Failed to store serial number");
	serial_number = std::string(ser_char);	//storing serial number into string
	OPENSSL_free(ser_char);	//free allocated memory
	return serial_bn;
}

openssl_certificate_base::~openssl_certificate_base(void)
{
	BN_free(serial_bn);	//free the generated number object resources
}


X509_CSR::X509_CSR(std::vector<std::string>& subject, std::shared_ptr<openssl_key_base> pubkey_ptr)
{
	if (pubkey_ptr->isPrivate())	//if the key is private not public
		throw std::runtime_error("Invalid key, CSR needs public key");
	csr = X509_REQ_new();	//create new csr
	if (!csr)
		throw std::runtime_error("Failed to create new CSR");
	X509_REQ_set_version(csr, 1);	//CSR only supports one version.
	if (X509_REQ_set_pubkey(csr, pubkey_ptr->GetKeyRaw()) != 1) 
	{
		X509_REQ_free(csr);	//free csr resources
		throw std::runtime_error("Failed to set public key to a new CSR");
	}
	X509_NAME* subject_name = X509_NAME_new();
	X509_NAME_add_entry_by_txt(subject_name, "C", MBSTRING_ASC, (unsigned char*)subject.at(0).c_str(), -1, -1, 0);	// country
	X509_NAME_add_entry_by_txt(subject_name, "ST", MBSTRING_ASC, (unsigned char*)subject.at(1).c_str(), -1, -1, 0);	//province
	X509_NAME_add_entry_by_txt(subject_name, "L", MBSTRING_ASC, (unsigned char*)subject.at(2).c_str(), -1, -1, 0);	// city/town
	X509_NAME_add_entry_by_txt(subject_name, "O", MBSTRING_ASC, (unsigned char*)subject.at(3).c_str(), -1, -1, 0);	// organization
	X509_NAME_add_entry_by_txt(subject_name, "CN", MBSTRING_ASC, (unsigned char*)subject.at(4).c_str(), -1, -1, 0);	// name/hostname
	X509_REQ_set_subject_name(csr, subject_name);
	X509_NAME_free(subject_name);	//free subject name memory
}



X509_CSR::X509_CSR(const std::string& csr_pem_file) : openssl_certificate_request_base(csr_pem_file)	//explicit forwarding
{
	file csr_file(csr_pem_file);
	std::vector<unsigned char> csr_vect = csr_file.read_binary();	//read file content and store in vector of unsigned char
	BIO* basicIO = BIO_new_mem_buf(csr_vect.data(), csr_vect.size());	//create basic IO and store csr inside it
	if (!basicIO)
		throw std::runtime_error("Failed to create new basicIO");
	csr = PEM_read_bio_X509_REQ(basicIO, nullptr,nullptr, nullptr);
	if (!csr)	//failed to read the csr
	{
		BIO_free(basicIO);	//free allocated buffer of basic IO
		throw std::runtime_error("Failed to load the CSR from its file");
	}
	BIO_free(basicIO);	//free allocated buffer of basic IO
}


X509_CSR::X509_CSR(const std::vector<unsigned char>& csr_data) : openssl_certificate_request_base()
{
	BIO* basicIO = BIO_new_mem_buf(csr_data.data(), csr_data.size());	//create basic IO and store csr inside it
	if (!basicIO)
		throw std::runtime_error("Failed to create new basicIO");
	csr = PEM_read_bio_X509_REQ(basicIO, nullptr, nullptr, nullptr);
	if (!csr)	//failed to read the csr
	{
		BIO_free(basicIO);	//free allocated buffer of basic IO
		throw std::runtime_error("Failed to load the CSR from its file");
	}
	BIO_free(basicIO);	//free allocated buffer of basic IO
}

void X509_CSR::SignCertificate(std::shared_ptr<openssl_key_base> privkey_ptr)
{
	if (!privkey_ptr->isPrivate())	//if the key is private not public
		throw std::runtime_error("Invalid key, CSR sign needs private key");
	if (!EVP_PKEY_can_sign(privkey_ptr->GetKeyRaw()))
		throw std::runtime_error("Provided key can't sign");
	EVP_PKEY* csr_pubkey = X509_REQ_get_pubkey(csr);
	if (!csr_pubkey)
		throw std::runtime_error("Failed to extract public key from CSR");
	//if the private key is not the pair of the public key
	if (EVP_PKEY_base_id(csr_pubkey) != EVP_PKEY_base_id(privkey_ptr->GetKeyRaw())) 
	{
		EVP_PKEY_free(csr_pubkey);  // Free the extracted public key
		throw std::runtime_error("Key type mismatch between CSR and private key");
	}
	EVP_PKEY_free(csr_pubkey);  // Free the extracted public key
	if (X509_REQ_sign(csr, privkey_ptr->GetKeyRaw(), EVP_sha256()) != 1)
		throw std::runtime_error("Failed to sign CSR");
}

bool X509_CSR::isCertificateSigned(std::shared_ptr<openssl_key_base> pubkey_ptr)
{
	if (pubkey_ptr->isPrivate())	//if the key is private not public
		throw std::runtime_error("Invalid key, CSR verification needs public key");
	if (!X509_REQ_verify(csr, pubkey_ptr->GetKeyRaw()))	//if certificate is not signed
		return false;
	return true;
}

void X509_CSR::Store(std::string& path)
{
	BIO* basicIO = BIO_new(BIO_s_mem());
	if (!basicIO)
		throw std::runtime_error("Failed to create new basicIO");
	if (PEM_write_bio_X509_REQ(basicIO, csr) != 1)//write the csr into the basicIO
	{
		BIO_free(basicIO);	//free allocated memory for basic IO
		throw std::runtime_error("Failed to write the csr into the basicIO");
	}
	unsigned char* CSRData = nullptr;	//ptr to char for storing csr data
	long CSRLen = BIO_get_mem_data(basicIO, &CSRData);	//storing basic IO content to the char* memory and getting its size
	if (CSRData == nullptr || CSRLen == 0)
	{
		BIO_free(basicIO);	//free allocated memory for basic IO
		throw std::runtime_error("Failed to write the csr into the file");
	}
	try //try block, because "file::write_binary" may thow an exception
	{
		file key_newfile(path);
		key_newfile.write_binary(std::vector<unsigned char>(CSRData, CSRData + CSRLen));	//write csr data to the file
	}
	catch (...)	//catch any exception
	{
		BIO_free(basicIO);	//free allocated memory for basic IO, in case of exception/error
		throw;	//rethrow the exception
	}
	if (cert_path.empty())	//if there's no path for the csr
		cert_path = path;	//set cert_path where the csr is stored
	BIO_free(basicIO);	//free allocated memory for basic IO
}

std::vector<unsigned char> X509_CSR::Serialize(void)
{
	BIO* basicIO = BIO_new(BIO_s_mem());
	if (!basicIO)
		throw std::runtime_error("Failed to create new basicIO");
	if (PEM_write_bio_X509_REQ(basicIO, csr) != 1)//write the csr into the basicIO
	{
		BIO_free(basicIO);	//free allocated memory for basic IO
		throw std::runtime_error("Failed to write the csr into the basicIO");
	}
	unsigned char* CSRData = nullptr;	//ptr to char for storing csr data
	long CSRLen = BIO_get_mem_data(basicIO, &CSRData);	//storing basic IO content to the char* memory and getting its size
	std::vector<unsigned char> serkey(CSRData, CSRData + CSRLen);
	BIO_free(basicIO);	//free allocated memory for basic IO
	return serkey;	//return serialized data
}
