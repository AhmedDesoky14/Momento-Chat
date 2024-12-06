#pragma once

#include "user.h"
#include "requests.h"
class user_services : public login_request, public register_request, public forgotpassword_request, public lock_request
{
public:
    bool req_login(user&) override;
    bool req_register(user&) override;
    bool req_forgotpassword(std::string) override;
    bool req_lock(user&) override;

};

// class authuser_services : public contact_request, public connect_request, public beacon_request
// {
// public:

// };

// class chatuser_services : public send_message, public receive_message
// {
// public:

// };
