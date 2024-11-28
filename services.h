#pragma once

#include "user.h"
#include "requests.h"
class user_services/* : public login_request, public register_request, public forgotpassword_request, public lock_request*/
{
private:
    user_services(void) = delete;
public:
    static bool req_login(user&);
    static bool req_register(user&);
    static bool req_forgotpassword(std::string);
};

class authuser_services/* : public contact_request, public connect_request, public beacon_request*/
{
public:

};

class chatuser_services/* : public send_message, public receive_message*/
{
public:

};
