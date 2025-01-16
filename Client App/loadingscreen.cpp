#include <chrono>
#include <future>
#include <thread>
#include "loadingscreen.h"
#include "serverconnection.h"

#include <iostream>
#include <QThread>
using namespace std;

using namespace std::chrono_literals;


loadingscreen::loadingscreen()
{
    cout << "oadingscreen::loadingscreen-> " << QThread::currentThread()->objectName().toStdString() << endl;

    UI.moveToThread(QCoreApplication::instance()->thread());//move UI object to main thread "UI thread"
    //Connect backend class signals with UI slots and assuring its running in main thread
    connect(this,&loadingscreen::ShowWindow,&UI,&loadingscreen_ui::ShowWindowSlot,Qt::QueuedConnection);
    connect(this,&loadingscreen::CloseWindow,&UI,&loadingscreen_ui::CloseWindowSlot,Qt::QueuedConnection);
    connect(this,&loadingscreen::SetLoadingBar,&UI,&loadingscreen_ui::SetLoadingBarSlot,Qt::QueuedConnection);
    connect(this,&loadingscreen::SetLoadingText,&UI,&loadingscreen_ui::SetLoadingTextSlot,Qt::QueuedConnection);
}

int loadingscreen::AppLoad(void)
{
    cout << "loadingscreen::AppLoad-> " << QThread::currentThread()->objectName().toStdString() << endl;

    std::string IP,Server;
    int time_count = 0;
    int ProgressBar_value = 0;
    int ConnectTask_result;
    bool finished_task = false; //boolean to check whether task is finished or not
    Loading_ShowWindow();
    std::future<int> ConnectTask = ServerConnection::Connect();
    while(!finished_task)
    {
        ++time_count;
        emit SetLoadingBar(ProgressBar_value++); //set loading bar value then increment
        if(time_count == Load_timeout)
            break;  //timeout
        if(ConnectTask.wait_for(15ms) == std::future_status::ready)
            finished_task = true;   //task finished
    }
    if(!finished_task)  //if task is out of time
    {
        ProgressBar_value = 0;
        emit SetLoadingBar(ProgressBar_value); //set loading bar to 100%
        emit SetLoadingText("Connection Failed, Please check internet connection","color: rgb(192, 28, 40);");
        std::this_thread::sleep_for(3s);    //sleep for 3 seconds
        Loading_CloseWindow();
        return -1;
    }
    else    //if task finshed
    {
        ConnectTask_result = ConnectTask.get();
        if(ConnectTask_result != 0) //if task finshed but not successfully
        {
            ProgressBar_value = 0;
            emit SetLoadingBar(ProgressBar_value); //set loading bar to 100%
            emit SetLoadingText("Connection Failed, Please check internet connection","color: rgb(192, 28, 40);");
            std::this_thread::sleep_for(3s);    //sleep for 3 seconds
            Loading_CloseWindow();
            return -1;
        }
        else //if task finshed successfully
        {
            IP = ServerConnection::GetIPAddress();
            if(IP == "NO_CONNECTION" || IP == "ERROR")  //IP Address error
            {
                ProgressBar_value = 0;
                emit SetLoadingBar(ProgressBar_value); //set loading bar to 100%
                emit SetLoadingText("Connection Failed, Please check internet connection","color: rgb(192, 28, 40);");
                std::this_thread::sleep_for(3s);    //sleep for 3 seconds
                Loading_CloseWindow();
                return -1;
            }
            Server = ServerConnection::GetServerIPAddress();
            if(Server == "NO_CONNECTION" || Server == "ERROR")  //Server IP Address error
            {
                emit SetLoadingText("Connection Failed, Please check internet connection","color: rgb(192, 28, 40);");
                std::this_thread::sleep_for(3s);    //sleep for 3 seconds
                Loading_CloseWindow();
                return -1;
            }
            emit SetLoadingText("Connected","color: rgb(38, 162, 105);");
            ProgressBar_value = 100;
            emit SetLoadingBar(ProgressBar_value); //set loading bar to 100%
            std::this_thread::sleep_for(2s);    //sleep for 2s
            Loading_CloseWindow();
            return 0;
        }
    }
}

int loadingscreen::AppOff(void)
{
    ServerConnection::Disconnect();
    return 0;
}
