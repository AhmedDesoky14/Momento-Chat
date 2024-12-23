#pragma once

#include <QObject>
#include <QMutex>

#include "loadingscreen.h"
#include "startmenu.h"
class app_main : public QObject
{
    Q_OBJECT
private:
    bool app_running = false;
    loadingscreen& loading_instance = loadingscreen::MakeInstance();
    startmenu& start_instance = startmenu::MakeInstance();

    app_main();
public:
    app_main(const app_main&) = delete; //delete copy constructor
    app_main& operator=(const app_main&) = delete;  //delete copy assignment operator
    inline static app_main* MakeInstance(void) //static function to get the single instance of the class
    {
        static app_main* instance_ptr = new app_main;   //static single instance of the class //Lazy initialization
        return instance_ptr;
    }
    inline static void DestroyInstance(app_main* ptr)
    {
        delete ptr;
    }
    void appmain_start(void);
    void appmain(void);
    void appmain_exit(void);
public slots:
    //void SuccessfullLogin(void);

signals:
    void TerminateProgram(void);
};

