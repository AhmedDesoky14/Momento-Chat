/************************************************************************************************************************
 * 	Module: message base class
 * 	File Name: message.cpp
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
#include "message.h"
/***********************************************************************************************************************
*                     					    Member Functions Implementation
***********************************************************************************************************************/
/************************************************************************************************************************
* Function: Parametrized Constructor
* Function ID[hex]: 0x00
* Parameters (in):  message type
*				    message sender ID
*				    message sender username
*					message sender registered name
* Parameters (out): NONE - Constructor
* Return value: NONE - Constructor
* Description: Parametrized constructor that creates the original message
************************************************************************************************************************/
message::message(message_type msg_t,std::pair<unsigned long long, std::string> v_sender,std::string v_sendername)
	:msg_type(msg_t),
	sender(v_sender.first,v_sender.second),
	sender_name(v_sendername)
{
	auto sys_time_now = std::chrono::system_clock::now();	//get current time in system clock
	std::time_t now_time_t = std::chrono::system_clock::to_time_t(sys_time_now); //convert to time_t type
	GMT_time = std::make_shared<std::tm>(*std::gmtime(&now_time_t));//store time for GMT+0 as reference in unique pointer
}
/************************************************************************************************************************
* Function: Parametrized Constructor for copied messages
* Function ID[hex]: 0x01
* Parameters (in):  message type
*				    message sender ID
*				    message sender username
*					message sender registered name
* 
* Parameters (out): NONE - Constructor
* Return value: NONE - Constructor
* Description: Parametrized constructor that creates the original message
************************************************************************************************************************/
message::message(message_type msg_t,std::pair<unsigned long long, std::string> v_sender,
							std::string v_sendername,std::shared_ptr<std::tm> v_gmt_time)
	:msg_type(msg_t),
	sender(v_sender.first,v_sender.second),
	sender_name(v_sendername),
	GMT_time(v_gmt_time){}
/************************************************************************************************************************
* Function: Copy Constructor
* Function ID[hex]: 0x02
* Parameters (in):  object to be copied
* Parameters (out): NONE - Constructor
* Return value: NONE - Constructor
* Description: Copy constructor that creates copy of a message
************************************************************************************************************************/
message::message(const message& obj_copy)
	:msg_type(obj_copy.msg_type),
	sender(obj_copy.sender.first,obj_copy.sender.second),GMT_time(obj_copy.GMT_time){}
/************************************************************************************************************************
* Function: Move Constructor
* Function ID[hex]: 0x03
* Parameters (in):  object to be moved
* Parameters (out): NONE - Constructor
* Return value: NONE - Constructor
* Description: Move constructor that moves ownership of a message
************************************************************************************************************************/
message::message(message&& obj_move)
	:msg_type(obj_move.msg_type),
	sender(obj_move.sender.first, obj_move.sender.second),
	sender_name(obj_move.sender_name),
	GMT_time(obj_move.GMT_time)
{
	obj_move.GMT_time = nullptr;
}
/************************************************************************************************************************
* Function: Get_message_date
* Function ID[hex]: 0x04
* Parameters (in):  regions UTC offset
* Parameters (out): message date and time
* Return value: message date and time
* Description: Function that process the instance of message creation
*			   and returns message date in time in the required UTC regions
************************************************************************************************************************/
std::string message::Get_message_date(int& utc_region_offset_hours)
{
	/*utc region is offset from gmt time [-12:12]*/
	std::stringstream sstr;	//string stream to store time output from "put_time" function and return it as string
	std::unique_ptr<std::tm> time_local = std::make_unique<std::tm>();
	time_local->tm_min = GMT_time->tm_min;
	time_local->tm_hour = GMT_time->tm_hour;
	time_local->tm_mday = GMT_time->tm_mday;
	time_local->tm_mon = GMT_time->tm_mon;
	time_local->tm_year = GMT_time->tm_year;
	time_local->tm_hour += utc_region_offset_hours;	//add time offset
	std::mktime(time_local.get()); // Normalize the structure in case of overflow (e.g., adding hours might push to next day)
	bool AM_PM_flag; //0=AM,1=PM
	if(time_local->tm_hour == 0)
	{
		time_local->tm_hour += 12;
		AM_PM_flag = 0;
	}
	else if(time_local->tm_hour == 12)
		AM_PM_flag = 1;
	else if(time_local->tm_hour > 12)
	{
		time_local->tm_hour -= 12;
		AM_PM_flag = 1;
	}
	else if(time_local->tm_hour < 12)
		AM_PM_flag = 0;
	sstr << std::put_time(time_local.get(), "%d/%m/%Y-%H:%M");
	if (AM_PM_flag)
		sstr << " PM";
	else
		sstr << " AM";
	return sstr.str();
}
