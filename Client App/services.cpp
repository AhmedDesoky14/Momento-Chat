#include "services.h"

bool user_services::req_login(user& usr)
{
    return true;
}

bool user_services::req_register(user& usr)
{
    return true;

}

bool user_services::req_forgotpassword(std::string email)
{
    return true;

}

bool user_services::req_lock(user&)
{

}

