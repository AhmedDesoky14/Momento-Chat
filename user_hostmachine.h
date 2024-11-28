#pragma once
#include <fstream>
#include <string>
#include "serverconnection.h"
#include "conf.h"
class user_hostmachine
{
private:
    std::string ServerIP;
    std::string CurrentIP;
    std::string OperatingSystem;
public:
    user_hostmachine(void)
    {
        ServerIP = ServerConnection::GetServerIPAddress();
        CurrentIP = ServerConnection::GetIPAddress();
        //Get hostmachine operating system
        OperatingSystem = HostMachine::GetOperatingSystem();
    }
    inline std::string Get_HostIP(void)
    {
        return CurrentIP;
    }
    inline std::string Get_ServerIP(void)
    {
        return ServerIP;
    }
    inline std::string GetOperSystem(void)
    {
        return OperatingSystem;
    }
    static std::string Get_CurrentTime(void)
    {
        std::string time;
#if(PLATFORM == LINUX)
        std::string time_command = "date > " + static_cast<std::string>(TIME_FILE);
#elif(PLATFORM == WINDOWS)
        std::string time_command = "date > " + static_cast<std::string>(TIME_FILE);
#endif
        std::system(time_command.c_str());
        std::ifstream file_data_stream(TIME_FILE,std::ios::in);//open TIME_FILE for input operations
        if(!file_data_stream.is_open()) //if file is not open
            return "ERROR";
        file_data_stream >> time;
        file_data_stream.close();
        return time;
    }
};

