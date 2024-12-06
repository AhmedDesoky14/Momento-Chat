#pragma once

#include <QMainWindow>
#include <QString>
#include "startmenu_window.h"

#include <iostream>
#include <QThread>
using namespace std;


class startmenu_ui : public QMainWindow
{
    Q_OBJECT
private:
    UI::StartMenuWindow StartMenu;
    startmenu_ui(void)
    {
        cout << "startmenu_ui::startmenu_ui-> " << QThread::currentThread()->objectName().toStdString() << endl;

        StartMenu.setupUi(this);
        //connect main buttons pushed signals with slots to emit signals to backend
        connect(StartMenu.LoginButton,&QPushButton::clicked,this,&startmenu_ui::TriggerLoginPressed,Qt::QueuedConnection);
        connect(StartMenu.RegisterEnterButton,&QPushButton::clicked,this,&startmenu_ui::TriggerRegisterPressed,Qt::QueuedConnection);
        connect(StartMenu.ForgotPasswordButton,&QPushButton::clicked,this,&startmenu_ui::TriggerForgotPasswordPressed,Qt::QueuedConnection);
        //connect buttons pushing with tabs changing
        connect(StartMenu.RegisterPushbutton,&QPushButton::clicked,this,&startmenu_ui::OpenRegisterTabSlot,Qt::QueuedConnection);
        connect(StartMenu.SupportPushButton,&QPushButton::clicked,this,&startmenu_ui::OpenSupportTabSlot,Qt::QueuedConnection);

    }
private slots:
    inline void OpenRegisterTabSlot(void)
    {
        cout << "OpenRegisterTabSlot-> " << QThread::currentThread()->objectName().toStdString() << endl;
        StartMenu.MainTabs->setCurrentIndex(1);
    }
    inline void OpenSupportTabSlot(void)
    {
        StartMenu.MainTabs->setCurrentIndex(1);
    }
    inline void TriggerLoginPressed(void)
    {
        emit LoginPressedSignal();
    }
    inline void TriggerRegisterPressed(void)
    {
        emit RegisterPressedSignal();
    }
    inline void TriggerForgotPasswordPressed(void)
    {
        emit ForgotPasswordPressedSignal();
    }
public:
    startmenu_ui(const startmenu_ui&) = delete; //delete copy constructor
    startmenu_ui& operator=(const startmenu_ui&) = delete;  //delete copy assignment operator
    inline static startmenu_ui& MakeInstance(void) //static function to get the single instance of the class
    {
        static startmenu_ui instance;   //static single instance of the class //Lazy initialization
        return instance;
    }
public slots:
    inline void ShowWindowSlot(void)
    {
        cout << "ShowWindowSlot-> " << QThread::currentThread()->objectName().toStdString() << endl;
        this->show();
    }
    inline void CloseWindowSlot(void)
    {
        this->close();
    }
    inline void SetLoginStatusSlot(QString text,QString Style)
    {
        StartMenu.label->setText(text);
        StartMenu.label->setStyleSheet(Style);
    }
    inline void SetRegisterStatusSlot(QString text,QString Style)
    {
        StartMenu.RegisterStatus->setText(text);
        StartMenu.RegisterStatus->setStyleSheet(Style);
    }
    inline void SetForgotPasswordStatusSlot(QString text,QString Style)
    {
        StartMenu.EmailSentStatus->setText(text);
        StartMenu.EmailSentStatus->setStyleSheet(Style);
    }
    inline void GetLoginUsernameSlot(void)
    {
        emit GetLoginUsernameSignal(StartMenu.username->text());
        //this QEvent loop to process pending signals events, used with signal slots pairs
        QEventLoop slot_loop;
        slot_loop.processEvents();
    }
    inline void GetLoginPasswordSlot(void)
    {
        emit GetLoginPasswordSignal(StartMenu.password->text());
        //this QEvent loop to process pending signals events, used with signal slots pairs
        QEventLoop slot_loop;
        slot_loop.processEvents();
    }
    inline void GetRegisterNameSlot(void)
    {
        emit GetRegisterNameSignal(StartMenu.RegisterName->text());
        //this QEvent loop to process pending signals events, used with signal slots pairs
        QEventLoop slot_loop;
        slot_loop.processEvents();
    }
    inline void GetRegisterUsernameSlot(void)
    {
        emit GetRegisterUsernameSignal(StartMenu.RegisterUsername->text());
        //this QEvent loop to process pending signals events, used with signal slots pairs
        QEventLoop slot_loop;
        slot_loop.processEvents();
    }
    inline void GetRegisterPasswordSlot(void)
    {
        emit GetRegisterPasswordSignal(StartMenu.RegisterPassword->text());
        //this QEvent loop to process pending signals events, used with signal slots pairs
        QEventLoop slot_loop;
        slot_loop.processEvents();
    }
    inline void GetRegisterRePasswordSlot(void)
    {
        emit GetRegisterRePasswordSignal(StartMenu.RegisterReenterPassword->text());
        //this QEvent loop to process pending signals events, used with signal slots pairs
        QEventLoop slot_loop;
        slot_loop.processEvents();
    }
    inline void GetRegisterEmailSlot(void)
    {
        emit GetRegisterEmailSignal(StartMenu.RegisterEmail->text());
        //this QEvent loop to process pending signals events, used with signal slots pairs
        QEventLoop slot_loop;
        slot_loop.processEvents();
    }
    void GetRegisterGenderSlot(void)
    {
        int index = StartMenu.RegisterGenderSelect->currentIndex();
        std::string gender;
        switch(index)
        {
            case 0:
                gender =  "Not selected";
                break;
            case 1:
                gender = "Male";
                break;
            case 2:
                gender = "Female";
                break;
            default:
                gender = "";
                break;
        }
        emit GetRegisterGenderSignal(QString::fromStdString(gender));   //cast std::string to QString
        //this QEvent loop to process pending signals events, used with signal slots pairs
        QEventLoop slot_loop;
        slot_loop.processEvents();
    }
    inline void GetRegisterBirthdateSlot(void)
    {
        emit GetRegisterBirthdateSignal(StartMenu.RegisterBirthDate->date().toString());
        //this QEvent loop to process pending signals events, used with signal slots pairs
        QEventLoop slot_loop;
        slot_loop.processEvents();
    }
    inline void GetForgotPasswordEmailSlot(void)
    {
        emit GetForgotPasswordEmailSignal(StartMenu.ForgotPasswordEmail->text());
        cout << "entered email: " << StartMenu.ForgotPasswordEmail->text().toStdString() << endl;
        //this QEvent loop to process pending signals events, used with signal slots pairs
        QEventLoop slot_loop;
        slot_loop.processEvents();
    }
signals:
    void LoginPressedSignal(void);
    void RegisterPressedSignal(void);
    void ForgotPasswordPressedSignal(void);
    //signals to call callback functions to get back the needed information
    void GetLoginUsernameSignal(QString);
    void GetLoginPasswordSignal(QString);
    void GetRegisterNameSignal(QString);
    void GetRegisterUsernameSignal(QString);
    void GetRegisterPasswordSignal(QString);
    void GetRegisterRePasswordSignal(QString);
    void GetRegisterEmailSignal(QString);
    void GetRegisterGenderSignal(QString);
    void GetRegisterBirthdateSignal(QString);
    void GetForgotPasswordEmailSignal(QString);
};

