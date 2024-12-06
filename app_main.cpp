#include "app_main.h"
#include <iostream>
#include <QThread>
using namespace std;


#include <thread>
using namespace std::chrono_literals;

app_main::app_main()
{

}

void app_main::appmain(void)    //main function
{
    cout << "app_main::appmain-> " << QThread::currentThread()->objectName().toStdString() << endl;
    // if(loading_instance.AppLoad() != 0) //Load Application
    // {
    //     this->appmain_exit();  //If not loaded return
    // }
    this->StartPhase(); //

    while(app_running)
    {

    }
}

void app_main::appmain_start(void)
{
    cout << "app_main::appmain_start-> " << QThread::currentThread()->objectName().toStdString() << endl;
    if(loading_instance.AppLoad() != 0)
    {
        this->appmain_exit();  //If not loaded return
    }
    app_running = true;
    this->appmain();
}

void app_main::appmain_exit(void)
{
    cout << "app_main::appmain_exit-> " << QThread::currentThread()->objectName().toStdString() << endl;

    app_running = false;
    loadingscreen::AppOff();     //Disconnect from server network
    emit TerminateProgram();    //emit signal to terminate program safely
}
















void app_main::StartPhase(void)
{
    start_instance.StartMenuShow();
    //while(start_instance.startmenu_running);
    std::this_thread::sleep_for(60s);
    start_instance.StartMenuClose();

    //it returns nothing, it will only close at successfull login
}

