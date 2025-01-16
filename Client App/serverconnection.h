#pragma once
#include <future>
#include <string>
#include <fstream>
#include <QObject>

#include "conf.h"

class ServerConnection
{
private:
    //static bool connectin_status; //connection status boolean
    ServerConnection() = delete;
public:
    static std::future<int> Connect(void);
    static void Disconnect(void);
    static std::string GetIPAddress(void);
    static std::string GetServerIPAddress(void);
};

class HostMachine
{
private:
    HostMachine() = delete;
public:
    static std::string GetOperatingSystem(void)
    {
        std::string os;
#if(PLATFORM == LINUX)
        std::string os_command = "grep '^NAME=' /etc/os-release | cut -d '\"' -f 2 > " + static_cast<std::string>(TEMP_FILE);
#elif(PLATFORM == WINDOWS)
        std::string os_command = "grep '^NAME=' /etc/os-release | cut -d '\"' -f 2 > " + static_cast<std::string>(TEMP_FILE);
#endif
        std::system(os_command.c_str());
        std::ifstream file_data_stream(TEMP_FILE,std::ios::in);//open TEMP_FILE for input operations
        if(!file_data_stream.is_open()) //if file is not open
            return "ERROR";
        file_data_stream >> os;
        file_data_stream.close();
        return os;
    }
};

