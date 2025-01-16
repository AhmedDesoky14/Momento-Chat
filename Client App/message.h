/************************************************************************************************************************
 * 	Module: message base class
 * 	File Name: message.h
 *  Authors: Ahmed Desoky
 *	Date: 31/10/2024
 *	*********************************************************************************************************************
 *	Description: message base class for other types of messages ex: text, image, file, voice note
 *				 this class disables default constructor and enables parametrized constructor
 *			     as the creating constructor of the original message
 *				 it enables copy and move semantics via constructors. 
 *				 it supports getting message date and time for all different UTC regions
 ***********************************************************************************************************************/
 /***********************************************************************************************************************
 *                     							 Header Files Included
 ***********************************************************************************************************************/
#pragma once
#include <string>
#include <utility>
#include <sstream>
#include <memory>
#include <chrono>
#include <ctime>
#include <iomanip>
class message
{
/***********************************************************************************************************************
*                     								Public Members
***********************************************************************************************************************/
public:
	enum class message_type {text,image,video,audio,file};	/*messages types*/
	message() = delete;	//explicitly deleted default constructor
	message(message_type, std::pair<unsigned long long,std::string>,std::string); //Original message parametrized constructor
	message(message_type, std::pair<unsigned long long,std::string>,std::string,std::shared_ptr<std::tm>); //Copy message parameterized constructor
	message(const message& obj_copy);	//copy constructor	//*not used*
	message(message&& obj_move);	//move constructor		//*not used*
	virtual ~message() = default;	//Virtual Destrcutor
	std::string Get_message_date(int&);
	inline std::pair<unsigned long long, std::string> Get_sender(void) const
	{
		return sender;
	}
	inline std::string Get_sender_name(void) const
	{
		return sender_name;
	}
	inline message_type Get_message_type(void) const
	{
		return msg_type;
	}
	//inline std::vector<std::byte> Get_Serialized(void)
	//{
	//	return data;
	//}
	//virtual std::vector<std::byte> Serialize_message(void) = 0;	//Pure virtual function
	//virtual void Deserialize_message(std::vector<std::byte>) = 0; //Pure virtual function

/***********************************************************************************************************************
*                     								Protected Members
***********************************************************************************************************************/
protected:

	const message_type msg_type;
	//const unsigned long long sender_id;
	const std::pair<unsigned long long,std::string> sender;
	//const std::string sender_username;
	const std::string sender_name;
	//std::vector<std::byte> data;
	//message_type msg_type;
	//unsigned long long sender_id;
	//std::string sender_username;
	//std::string sender_name;
	std::shared_ptr<std::tm> GMT_time = nullptr;
	//struct message_header
	//{
	//	message_type msg_type;
	//	unsigned long long msg_size;
	//}msg_header;
};