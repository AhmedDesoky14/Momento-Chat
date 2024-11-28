#include <future>
#include <thread>
#include <chrono>
#include <fstream>

#include "serverconnection.h"

#include <iostream>
#include <QThread>
using namespace std;

using namespace std::chrono_literals;

static bool connectin_status = false;   //Global private variable in this file

#if(SERVER == 0)    //For Local Network, to check if connected to local network or not
std::future<int> ServerConnection::Connect(void)
{
    //Lambda expression to perform connection task asynchronously
    return std::async(std::launch::async,[]()->int //return type is int
    {
#if (PLATFORM == LINUX)
        std::string gatway;
        std::string checkgateway_command = "ip route | grep default | awk '{print $3}' > " + static_cast<std::string>(TEMP_FILE);
        std::system(checkgateway_command.c_str());
        std::ifstream file_data_stream(TEMP_FILE,std::ios::in);//open TEMP_FILE for input operations
        if(!file_data_stream.is_open()) //if file is not open
            return -1;
        file_data_stream >> gatway;
        file_data_stream.close();   //close file
        if(gatway.empty())
            return -1;  //no gatway found
        return 0;   //gatway found if not the string is not empty
#elif(PLATFORM == WINDOWS)
        std::string gateway;
        std::string checkgateway_command = "for /f "tokens=3" %G in ('ipconfig ^| findstr "Default Gateway"') do @echo %G > " + static_cast<std::string>(TEMP_FILE);
        std::system(checkgateway_command.c_str());
        std::ifstream file_data_stream(TEMP_FILE,std::ios::in);//open TEMP_FILE for input operations
        if(!file_data_stream.is_open()) //if file is not open
            return -1;
        file_data_stream >> gatway;
        file_data_stream.close();
        if(std::count(gateway.begin(),gateway.end(),'.') > 1)
            return 0;   //A gateway found
        //else didn't get gateway, try the second command
        file_data_stream.close();   //close file
        gatway.clear(); //clear the string
        std::string checkgateway_command2 = "for /f "tokens=13" %G in ('ipconfig ^| findstr "Default Gateway"') do @echo %G > " + static_cast<std::string>(TEMP_FILE);
        std::system(checkgateway_command.c_str());
        std::ifstream file_data_stream(TEMP_FILE,std::ios::in);//open TEMP_FILE for input operations
        if(!file_data_stream.is_open()) //if file is not open
            return -1;
        file_data_stream >> gatway;
        file_data_stream.close();
        if(std::count(gateway.begin(),gateway.end(),'.') > 1)
            return 0;   //A gateway found
        file_data_stream.close();   //close file
        return -1;  //No gateway found, not connecteds
#endif
    });
}
void ServerConnection::Disconnect(void)
{
    //Do nothing, machine keeps connecting to the local network
    return;
}
std::string ServerConnection::GetServerIPAddress(void)
{
    return static_cast<std::string>(LOCALSERVER_IP);
}
std::string ServerConnection::GetIPAddress(void)
{
#if(PLATFORM == LINUX)
    std::string ip;
    std::string GetIP_command = "hostname -I | cut -d ' ' -f1 > " + static_cast<std::string>(TEMP_FILE);
    std::system(GetIP_command.c_str());
    std::ifstream file_data_stream(TEMP_FILE,std::ios::in);//open TEMP_FILE for input operations
    if(!file_data_stream.is_open()) //if file is not open
        return "ERROR";
    file_data_stream >> ip;

    if(std::count(ip.begin(),ip.end(),'.') > 1)
        return "NO_CONNECTION";
    return ip;
#elif(PLATFORM == WINDOWS)




#endif
}





#elif(SERVER == 1)
std::future<int> ServerConnection::Connect(void)
{
    cout << "ServerConnection::Connect-> " << QThread::currentThread()->objectName().toStdString() << endl;
    //Lambda expression to perform connection task asynchronously
    return std::async(std::launch::async,[]()->int //return type is int
    {
        if(std::system(ConnectVPN_script) != 0)
        {
            std::this_thread::sleep_for(3s);
            connectin_status = false;
            return -1;
        }
        connectin_status = true;
        return 0;
    });
}
void ServerConnection::Disconnect(void)
{
    std::system("tailscale down");
    connectin_status = false;
    return;
}
std::string ServerConnection::GetServerIPAddress(void)
{
    return "";
}
std::string ServerConnection::GetIPAddress(void)
{
    cout << "ServerConnection::GetIPAddress-> " << QThread::currentThread()->objectName().toStdString() << endl;
    if(!connectin_status)
        return "NO_CONNECTION";
    std::string ip_command = "tailscale ip -4 > " + static_cast<std::string>(TEMP_FILE);
    std::system(ip_command.c_str());
    std::ifstream file_data_stream(TEMP_FILE,std::ios::in);//open TEMP_FILE for input operations
    if(!file_data_stream.is_open()) //if file is not open
        return "ERROR";
    std::string ip;
    file_data_stream >> ip;
    file_data_stream.close();
    return ip;
}




#elif(SERVER == 2)
std::future<int> ServerConnection::Connect(void)
{

}
void ServerConnection::Disconnect(void)
{

}
std::string ServerConnection::GetServerIPAddress(void)
{

}
std::string ServerConnection::GetIPAddress(void)
{

}
#endif
