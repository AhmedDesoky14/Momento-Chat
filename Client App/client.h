#pragma once
#include <openssl/rand.h>
#include <openssl/evp.h>
#include <openssl/sha.h>
#include <filesystem>
#include <utility>
#include <string>
#include <vector>
#include <memory>
class client
{
public: 
	enum client_status { C_OK, C_NOT_OK, C_ERROR };



	client() = default;
	//client() = default;		//constructor for login
	//client() = default;	//constructor for signup
	
	static std::unique_ptr<client> ClientSignUp(void);
	static client_status ClientLogin(void);


	static std::unique_ptr<client> runLogin(void);
	static std::unique_ptr<client> runSignUp(void);

	bool setPassword(const std::string& password);
	bool verifyPassword(const std::string& password);

	inline unsigned long long Get_UserID(void) const
	{
		return usr.first;
	}
	inline std::string Get_Username(void) const
	{
		return usr.second;
	}
	inline std::string Get_Email(void) const
	{
		return email;
	}
	inline std::string Get_Clientname(void) const
	{
		return client_name;
	}
	inline int Get_PasswordIterations(void) const
	{
		return password_iterations;
	}
	inline unsigned long long Get_MessagesSent(void) const
	{
		return messages_sent;
	}
	inline unsigned long long Get_MessagesRecieved(void) const
	{
		return messages_received;
	}
	inline unsigned long long Get_MessagesTotal(void) const
	{
		return messages_sent + messages_received;
	}
	//client_status Client_SignUp()


private:
	const std::pair<unsigned long long,std::string> usr;
	std::string client_name;
	std::string email;
	std::vector<unsigned char> password_salt;
	std::vector<unsigned char> hashed_password;
	int password_iterations = 0;
	//bool certified = false;
	bool online = false;
	//certificate
	//public key
	//private key	//key chain
	unsigned long long messages_sent;
	unsigned long long messages_received;
	std::string current_IP_address;
	int UTC_Region;
	/*
		Activity Feature
	*/
	//std::filesystem::path	
	const unsigned int min_password_len = 8;







};

