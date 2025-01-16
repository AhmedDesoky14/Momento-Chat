#include "keys.h"

openssl_key_base::openssl_key_base(void)
{
	key = EVP_PKEY_new();	//creating new key
	if (!key)
		throw std::runtime_error("Failed to create new key");
}

openssl_key_base::openssl_key_base(const std::vector<unsigned char>& keydata)
{
	BIO* basicIO = BIO_new_mem_buf(keydata.data(), keydata.size());	//create basic IO and store key inside it
	if(!basicIO)
		throw std::runtime_error("Failed to create new basicIO");
	key = PEM_read_bio_PUBKEY(basicIO, nullptr, nullptr, nullptr);	//read the key in PEM format to the EVP_PKEY ptr "key"
	if (key == nullptr)	//if not public key, try to read as private key
	{
		BIO_seek(basicIO, 0); //reset the basicIO to read from the begining again
		key = PEM_read_bio_PrivateKey(basicIO, nullptr, nullptr, nullptr);	//read the private key in PEM format to the EVP_PKEY ptr "key"
		if (key == nullptr)	//if neither a private key nor public key
		{
			BIO_free(basicIO);	//free allocated buffer of basic IO
			throw std::runtime_error("Failed to load key, Invalid key");
		}
	}
	BIO_free(basicIO);	//free allocated buffer of basic IO
}

openssl_key_base::openssl_key_base(EVP_PKEY* key_par)
{
	if (key_par == nullptr)
		throw std::runtime_error("Invalid key object constructed");
	key = key_par;
}

openssl_key_base::openssl_key_base(const std::string& path) : key_path(path)
{
	file key_file(path);
	std::vector<unsigned char> key_vect = key_file.read_binary();	//read file content and store in vector of unsigned char
	BIO* basicIO = BIO_new_mem_buf(key_vect.data(), key_vect.size());	//create basic IO and store key inside it
	if (!basicIO)
		throw std::runtime_error("Failed to create new basicIO");
	key = PEM_read_bio_PUBKEY(basicIO, nullptr, nullptr, nullptr);	//read the key in PEM format to the EVP_PKEY ptr "key"
	if (key == nullptr)	//if not public key, try to read as private key
	{
		BIO_seek(basicIO, 0); //reset the basicIO to read from the begining again
		key = PEM_read_bio_PrivateKey(basicIO, nullptr, nullptr, nullptr);	//read the private key in PEM format to the EVP_PKEY ptr "key"
		if (key == nullptr)	//if neither a private key nor public key
		{
			BIO_free(basicIO);	//free allocated buffer of basic IO
			throw std::runtime_error("Failed to load key, Invalid key");
		}
	}
	BIO_free(basicIO);	//free allocated buffer of basic IO
}

openssl_key_base::~openssl_key_base(void)
{
	EVP_PKEY_free(key);	//free key's memory allocated
}

void openssl_key_base::StoreKey(std::string& filepath)
{
	BIO* basicIO = BIO_new(BIO_s_mem());
	if (!basicIO)
		throw std::runtime_error("Failed to create new basicIO");
	if (!PEM_write_bio_PrivateKey(basicIO, key, nullptr, nullptr, 0, nullptr, nullptr))//assume private key and write to the basic IO object
	{
		//key is not private, try to write public key
		BIO_seek(basicIO, 0); //reset the basicIO to write at the begining again
		if (!PEM_write_bio_PUBKEY(basicIO, key))	//write public key to the basic IO object
		{
			BIO_free(basicIO);	//free allocated memory for basic IO
			throw std::runtime_error("Failed to write private key to basicIO");
		}
		filepath.erase(filepath.end() - 4, filepath.end());	//remove last 4 characters of the filepath name
		filepath += "-public.pem";	//add -pubic to file name
	}
	unsigned char* keyData = nullptr;	//ptr to char for storing key data
	long keyLen = BIO_get_mem_data(basicIO, &keyData);	//storing basic IO content to the char* memory and getting its size
	if (keyData == nullptr || keyLen == 0)
	{
		BIO_free(basicIO);	//free allocated memory for basic IO
		throw std::runtime_error("Failed to write the key into the file");
	}
	try //try block, because "file::write_binary" may throw an exception
	{
		file key_newfile(filepath);
		key_newfile.write_binary(std::vector<unsigned char>(keyData, keyData + keyLen));	//write key data to the file
	}
	catch (...)	//catch any exception
	{
		BIO_free(basicIO);	//free allocated memory for basic IO, in case of exception/error
		throw;	//rethrow the exception
	}
	if (key_path.empty())	//if there's no path for the key
		key_path = filepath;	//set key_path where the key is stored
	BIO_free(basicIO);	//free allocated memory for basic IO
}

std::vector<unsigned char> openssl_key_base::SerializeKey(void)
{
	BIO* basicIO = BIO_new(BIO_s_mem());
	if (!basicIO)
		throw std::runtime_error("Failed to create new basicIO");
	if (!PEM_write_bio_PrivateKey(basicIO, key, nullptr, nullptr, 0, nullptr, nullptr))//assume private key and write to the basic IO object
	{
		//key is not private, try to write public key
		BIO_seek(basicIO, 0); //reset the basicIO to write at the begining again
		if (!PEM_write_bio_PUBKEY(basicIO, key))	//write public key to the basic IO object
		{
			BIO_free(basicIO);	//free allocated memory for basic IO
			throw std::runtime_error("Failed to write private key to basicIO");
		}
	}
	unsigned char* keyData;	//ptr to char for storing key data
	long keyLen = BIO_get_mem_data(basicIO, &keyData);	//storing basic IO content to the char* memory and getting its size
	if (keyData == nullptr || keyLen == 0)
	{
		BIO_free(basicIO);	//free allocated memory for basic IO
		throw std::runtime_error("Failed to write the key into the file");
	}
	std::vector<unsigned char> serkey(keyData, keyData + keyLen);
	BIO_free(basicIO);	//free allocated memory for basic IO
	return serkey;	//return serialized data
}

RSA_key::RSA_key(void) : openssl_key_base()	//call the non-paramterized constructor explicitly
{
	//the base constructor will create the new key container
	RSA* rsa_key = RSA_generate_key(2048, RSA_F4, nullptr, nullptr);
	if(!rsa_key)
		throw std::runtime_error("Failed to create RSA key");
	if (!EVP_PKEY_assign_RSA(key, RSAPrivateKey_dup(rsa_key)))
	{
		RSA_free(rsa_key);
		throw std::runtime_error("Failed to assign RSA type to the key");
	}
	RSA_free(rsa_key);
}

bool RSA_key::isPrivate(void)
{
	std::vector<unsigned char> key_serialized = SerializeKey();
	std::string keystring(key_serialized.begin(), key_serialized.end());
	if (keystring.find("PRIVATE") == std::string::npos)
		return false;	//key is a public key
	return true;	//key is private key
}

EVP_PKEY* RSA_key::DerivePublicKey(void)
{
	if (!isPrivate())	//if the key is not the private key
		throw std::runtime_error("Failed to derive public key, private key needed");
	RSA* rsa_key = EVP_PKEY_get1_RSA(key);  // key containing both public and private key
	EVP_PKEY* public_key = EVP_PKEY_new();
	if (!public_key)
	{
		RSA_free(rsa_key);
		throw std::runtime_error("Failed to create new public key");
	}
	EVP_PKEY_assign_RSA(public_key, RSAPublicKey_dup(rsa_key));  // Derive the public key from RSA and assign to the new EVP_PKEY
	RSA_free(rsa_key);  // Clean up the RSA object's memory as it's no longer needed
	return public_key;
}
