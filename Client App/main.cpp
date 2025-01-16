
#include <QApplication>
#include <QThread>
#include "conf.h"
#include "app_main.h"

#include <iostream>
using namespace std;
#include "serverconnection.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QThread AppThread;
    AppThread.setObjectName("Backend Thread");
    QThread::currentThread()->setObjectName("UI Thread");
    app_main* app_instance = app_main::MakeInstance(); //make the only instance for backend main class
    app_instance->moveToThread(&AppThread);  //move the backend main class to the secondary thread
    //once thread start, trigger "app_main::appmain_start" function
    QObject::connect(&AppThread,&QThread::started,app_instance,&app_main::appmain_start);
    QObject::connect(&app,&QApplication::aboutToQuit,[&]()
                    {
        cout << "Lambda about to quit-> " << QThread::currentThread()->objectName().toStdString() << endl;
                        app_instance->appmain_exit();    //if main window closed, exit all backend operationss
                        AppThread.quit();
                        AppThread.wait();
                    });
    QObject::connect(app_instance,&app_main::TerminateProgram,[=]()
                    {
                        app_main::DestroyInstance(app_instance);
                        std::exit(0);   //Terminate Program
                    });
    cout << "main-> " << QThread::currentThread()->objectName().toStdString() << endl;
    AppThread.start();  //start backend thread
    return app.exec();
}
