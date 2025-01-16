#pragma once



#include <QObject>
#include <QString>
#include "loadingscreen_ui.h"
class loadingscreen : public QObject
{
    Q_OBJECT
private:
    const int Load_timeout = 500;   //15*500ms = 7.5seconds //Application loading timout


    loadingscreen();  //Private constructor
    loadingscreen_ui& UI = loadingscreen_ui::MakeInstance();    //User Interface instance
public:
    loadingscreen(const loadingscreen&) = delete; //delete copy constructor
    loadingscreen& operator=(const loadingscreen&) = delete;  //delete copy assignment operator
    inline static loadingscreen& MakeInstance(void) //static function to get the single instance of the class
    {
        cout << "static loadingscreen& MakeInstance-> " << QThread::currentThread()->objectName().toStdString() << endl;
        static loadingscreen instance;   //static single instance of the class //Lazy initialization
        return instance;
    }
    inline void Loading_ShowWindow(void)
    {
        emit ShowWindow();
    }
    inline void Loading_CloseWindow(void)
    {
        emit CloseWindow();
    }
    int AppLoad(void);
    static int AppOff(void);
signals:
    void ShowWindow(void);
    void CloseWindow(void);
    void SetLoadingBar(int);
    void SetLoadingText(QString,QString);
};

