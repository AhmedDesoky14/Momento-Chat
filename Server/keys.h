#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <openssl/rsa.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include "utils.h"
#include "conf.h"

//static void InitOpenSSL(void)
//{
//	OpenSSL_add_all_algorithms();
//	return;
//}

class openssl_key_base
{
protected:
	EVP_PKEY* key;	//Note: public key can be extracted from the private key, so the work is on the private key mainly
	std::string key_path;
	openssl_key_base(void);	//non-paramterized constructor, new created key (private key)
	openssl_key_base(const std::vector<unsigned char>&);//parameterized constructor, already existed key but serialized
	openssl_key_base(EVP_PKEY*);
	openssl_key_base(const std::string&);	//parameterized constructor, already existed key
	virtual ~openssl_key_base(void);//base virtual destructor
public:
	void StoreKey(std::string&);
	std::vector<unsigned char> SerializeKey(void);
	virtual bool isPrivate(void) = 0;	//pure virtual function
	virtual EVP_PKEY* DerivePublicKey(void) = 0;	//pure virtual function
	inline std::string GetPath(void) const
	{
		return key_path;
	}
	inline EVP_PKEY* GetKeyRaw(void) const
	{
		return key;
	}
};

class RSA_key : public openssl_key_base
{
public:
	RSA_key(void);	
	RSA_key(std::vector<unsigned char>& key_Data) : openssl_key_base(key_Data) {}	//call the paramterized constructor explicitly
	RSA_key(EVP_PKEY* key_par) : openssl_key_base(key_par) {} //call the paramterized constructor explicitly
	RSA_key(const std::string& path) : openssl_key_base(path) {}	//call the paramterized constructor explicitly
	virtual ~RSA_key(void) = default;
	bool isPrivate(void) override;
	EVP_PKEY* DerivePublicKey(void) override;
};

class ServerKey final : public RSA_key	//final class
{
public:
	ServerKey(void) : RSA_key(std::string(SERVER_KEY)) {}	
};
