#pragma once
#include <QMainWindow>
#include <QObject>
#include <QString>
#include "loadingscreen_window.h"

#include <iostream>
#include <QThread>
using namespace std;

class loadingscreen_ui : public QMainWindow
{
    Q_OBJECT
private:
    UI::LoadingScreenWindow LoadingScreen;
    loadingscreen_ui(void)  //Private constructor
    {
        LoadingScreen.setupUi(this);
    }
public:
    loadingscreen_ui(const loadingscreen_ui&) = delete; //delete copy constructor
    loadingscreen_ui& operator=(const loadingscreen_ui&) = delete;  //delete copy assignment operator
    inline static loadingscreen_ui& MakeInstance(void) //static function to get the single instance of the class
    {
        cout << "static loadingscreen_ui& MakeInstance-> " << QThread::currentThread()->objectName().toStdString() << endl;
        static loadingscreen_ui instance;   //static single instance of the class //Lazy initialization
        return instance;
    }
public slots:
    inline void ShowWindowSlot(void)
    {
        this->show();
    }
    inline void CloseWindowSlot(void)
    {
        this->close();
    }
    inline void SetLoadingBarSlot(int val)
    {
        LoadingScreen.LoadingBar->setValue(val);
    }
    inline void SetLoadingTextSlot(QString text,QString Style)
    {
        LoadingScreen.LoadingText->setText(text);
        LoadingScreen.LoadingText->setStyleSheet(Style);
    }
};

