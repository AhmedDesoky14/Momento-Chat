#pragma once
#include <vector>
#include <string>
#include <utility>
#include "user_hostmachine.h"
class user
{
private:
    bool usr_locked = false;
    std::string password1_temp;
    std::string password2_temp;
protected:
    user_hostmachine hostmachine;
    std::pair<std::string,unsigned long long> user_entity = {"",0};
    std::string name;
    std::string email;
    std::string gender;
    std::string birthdate;
public:
    user(void)
    {

    }
    void clear(void)
    {
        password1_temp.clear();
        password2_temp.clear();
        user_entity.first.clear();
        user_entity.second = 0;
        name.clear();
        email.clear();
        gender.clear();
        birthdate.clear();

    }
    inline std::string GetServerIP(void)
    {
        return hostmachine.Get_ServerIP();
    }
    inline std::string GetIP(void)
    {
        return hostmachine.Get_HostIP();
    }
    inline std::string GetOS(void)
    {
        return hostmachine.GetOperSystem();
    }
    inline std::string GetTime(void)
    {
        return user_hostmachine::Get_CurrentTime();
    }
    inline void SetUsername(std::string usrnm)
    {
        user_entity.first = usrnm;
    }
    inline std::string GetUsername(void)
    {
        return user_entity.first;
    }
    inline void SetUserID(unsigned long long ID)
    {
        user_entity.second = ID;
    }
    inline bool CheckUserLocked(void)
    {
        return usr_locked;
    }
    inline void SetUserLocked(bool lck)
    {
        usr_locked = lck;
    }
    inline void SetName(std::string nm)
    {
        name = nm;
    }
    inline std::string GetName(void)
    {
        return name;
    }
    inline void SetEmail(std::string eml)
    {
        email = eml;
    }
    inline std::string GetEmail(void)
    {
        return email;
    }
    inline void SetGender(std::string gndr)
    {
        gender = gndr;
    }
    inline std::string GetGender(void)
    {
        return gender;
    }
    inline void SetBirthdate(std::string date)
    {
        birthdate = date;
    }
    inline std::string GetBirthdate(void)
    {
        return birthdate;
    }
    inline void SetEnteredPassword(std::string pswd)
    {
        password1_temp = pswd;
    }
    inline std::string GetEnteredPassword(void)
    {
        return password1_temp;
    }
    inline void SetEnteredPassword2(std::string pswd)
    {
        password2_temp = pswd;
    }
    inline std::string GetEnteredPassword2(void)
    {
        return password2_temp;
    }
};

