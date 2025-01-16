#pragma once
#include "server_messages.pb.h"
class server_message_abstract
{
public:
	enum class MessageType 
	{
		DEFAULT = 0, RegisterMessage = 1, LoginMessage = 2, ForgotAccountMessage = 3,
        CheckUserStatusMessage = 4, ConnectionMessage = 5, ChangePasswordMessage = 6,
        UpdateMessage = 7, BlockMessage = 8, UnBlockMessage = 9, GetBlocklistMessage = 10
	};
	inline MessageType GetType(void) const
	{
		return type;
	}
protected:
	MessageType type;
};


class server_message : public server_message_abstract
{

};


