#include "app_main.h"

#include <iostream>
#include <thread>
#include <QThread>


using namespace std;


using namespace std::chrono_literals;

app_main::app_main()
{}

void app_main::appmain(void)    //main function
{
    cout << "app_main::appmain-> " << QThread::currentThread()->objectName().toStdString() << endl;
    cout << "app running status: " << app_running << endl;
    while(app_running)
    {
        cout << "Running the program" << endl;
        std::this_thread::sleep_for(1000ms);
    }
}

void app_main::appmain_start(void)
{
    cout << "app_main::appmain_start-> " << QThread::currentThread()->objectName().toStdString() << endl;
    if(loading_instance.AppLoad() != 0)
    {
        this->appmain_exit();  //If not loaded return
    }
    start_instance.StartMenuShow(); //Loaded and connected to the server successfully
    if(!start_instance.StartMenu_Task())
    {
        this->appmain_exit();  //If failed
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



