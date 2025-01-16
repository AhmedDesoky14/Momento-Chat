#pragma once

#include "user.h"
//Applying ISP + SRP + OCP

class login_request
{
public:
    virtual bool req_login(user&) = 0;
};
class lock_request
{
public:
    virtual bool req_lock(user&) = 0;
};

class register_request
{
public:
    virtual bool req_register(user&) = 0;
};

class forgotpassword_request
{
public:
    virtual bool req_forgotpassword(std::string) = 0;
};

class contact_request
{
public:
    virtual void req_contact() = 0;
};

class connect_request
{
public:
    virtual void req_connect() = 0;
};
class beacon_request
{
public:
    virtual void send_beacon() = 0;
};

class send_message
{
public:
    virtual void send(void) = 0;
};

class receive_message
{
public:

};
