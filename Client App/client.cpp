#include "client.h"
#include <atomic>
#include <future>
#include <csignal>
#include <opencv2/opencv.hpp>

#include <rang.hpp>
static std::atomic<bool> exit_signup = false;	//private atmoic boolean variable to control threads in this file



std::unique_ptr<client> client::runSignUp(void)
{
	auto signal_handler = [](int signum) //Lambda expression to to handle signals if one of the next signals occured
	{
		//Lambda expression signature must be exactly like this, refer to "std::signal" in cppreference.com
		exit_signup = true;
	};
	std::signal(SIGINT,signal_handler);		// Catch CTRL+C signal for signup thread
	std::signal(SIGHUP,signal_handler);		// Catch terminal close signal for signup thread
	std::signal(SIGTERM,signal_handler);	// Catch kill command signal for signup thread
	//start async thread, it returns object of client class
	std::future<std::unique_ptr<client>> operation_result = std::async(client::ClientSignUp);
	std::unique_ptr<client> signup_client = operation_result.get();
	if(signup_client == nullptr)	//blocking the main program until signup is exitted by any means
	{



		std::signal(SIGINT, SIG_DFL);  // Reset handling for Ctrl+C (Interrupt)
		std::signal(SIGHUP, SIG_DFL);  // Reset handling for terminal close
		std::signal(SIGTERM, SIG_DFL); // Reset handling for termination signals
		exit_signup = false;
		return nullptr;
	}
	std::signal(SIGINT, SIG_DFL);  // Reset handling for Ctrl+C (Interrupt)
	std::signal(SIGHUP, SIG_DFL);  // Reset handling for terminal close
	std::signal(SIGTERM, SIG_DFL); // Reset handling for termination signals
	exit_signup = false;
	return std::move(signup_client);	//return the object and move ownership
}

std::unique_ptr<client> client::ClientSignUp(void)
{
	bool signup_success = false;
	while (!exit_signup)
	{






		//if (cv::waitKey(1) == 'q')	//if 'q' key is pressed, set exit signup
		//	exit_signup = true;

	}
	if(!signup_success)
	{
		std::cout << "\n\n\n\n\n" << std::string(80,' ');	//setting padding
		std::cout << rang::style::bold << rang::fg::cyan << "Signed Up successfully" << rang::style::reset << std::endl;
		std::cout << rang::style::bold << rang::fg::green << "Welcome to abc" << rang::style::reset << std::endl;


	}
	else
	{

	}
	return std::move(std::make_unique<client>());
}

//client::client_status client::ClientLogin(void)
//{
//
//
//
//
//	return client_status();
//}













bool client::setPassword(const std::string& password)
{
	if(password.size() < min_password_len)
	{
		return false;
	}
	password_salt.resize(SHA256_DIGEST_LENGTH);	//Resize password salt vector to 32 byte
	RAND_bytes(password_salt.data(), password_salt.size());	//Generate salt
	hashed_password.resize(SHA256_DIGEST_LENGTH); //Resize hashed password vector to 32 byte
	std::vector<unsigned char> saltedPassword(password.begin(),password.end());
	//Insert generted salt to the password to be set
	saltedPassword.insert(saltedPassword.end(),password_salt.begin(),password_salt.end());
	//Generate password hash and store it in the "hashed_password" data member
	SHA256(saltedPassword.data(), saltedPassword.size(), hashed_password.data());
	return true;
}

bool client::verifyPassword(const std::string& password)
{
	std::vector<unsigned char> verify_hash(SHA256_DIGEST_LENGTH);
	std::vector<unsigned char> verify_saltedpassword(password.begin(), password.end());
	verify_saltedpassword.insert(verify_saltedpassword.end(), password_salt.begin(), password_salt.end());
	//after adding the same salt to the input password, generate the hash and compare it with the stored hash
	SHA256(verify_saltedpassword.data(), verify_saltedpassword.size(),verify_hash.data());
	return ((verify_hash == hashed_password) ? true : false);	//ternary operator
}
