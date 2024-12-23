#pragma once
#include "message.h"
#include <algorithm>
class text_message : public message
{
private:
	std::string text;
public:
	text_message() = delete;
	text_message(message_type type, std::pair<unsigned long long,std::string> user, std::string s_usr, std::string txt)
		:message(type,user,s_usr),text(txt){}
	text_message(text_message& obj_copy):
		message(obj_copy.msg_type, obj_copy.sender, obj_copy.sender_name, obj_copy.GMT_time),
		text(obj_copy.text) {}
	text_message(text_message&& obj_move):
		message(obj_move.msg_type, obj_move.sender, obj_move.sender_name, obj_move.GMT_time),
		text(obj_move.text) {}
	~text_message() = default;
	inline std::string Get_text_message() const
	{
		return text;
	}
	//inline std::vector<std::byte> Serialize_message(void) override
	//{
	//	data.insert(data.end(),reinterpret_cast<std::byte*>(&msg_header),reinterpret_cast<std::byte*>(&msg_header)+sizeof(msg_header));
	//	data.insert(data.end(), text.begin(), text.end());
	//	return data;
	//	//for(char c : text)
	//	//{
	//	//	data.push_back(static_cast<std::byte> (c));
	//	//}
	//	//std::transform(text.begin(),text.end(),data.end(),
	//	//	[](char c)	//Lambda expression to the std::transform to return a casted type of char c of each character
	//	//	{			//in std::string  to std::byte type
	//	//		return std::byte(c);
	//	//	}
	//	//);
	//}
	//inline void Deserialize_message(std::vector<std::byte> vect) override
	//{

	//}
};

