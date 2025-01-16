#pragma once
#include <string>
#include <QObject>
#include <QString>
#include "startmenu_ui.h"
#include "services.h"
#include "user.h"
#include "conf.h"

class startmenu : public QObject
{
    Q_OBJECT
private:
    user start_user;
    user_services start_client;
    startmenu(void);

    startmenu_ui& UI = startmenu_ui::MakeInstance();
    bool successfull_login = false;


public:


    startmenu(const startmenu&) = delete; //delete copy constructor
    startmenu& operator=(const startmenu&) = delete;  //delete copy assignment operator
    inline static startmenu& MakeInstance(void) //static function to get the single instance of the class
    {
        static startmenu instance;   //static single instance of the class //Lazy initialization
        return instance;
    }
    inline void StartMenuShow(void)
    {
        emit ShowWindow();
    }
    inline void StartMenuClose(void)
    {
        emit CloseWindow();
    }
    bool StartMenu_Task(void);
    // inline bool check_successfull_login(void)
    // {
    //     return successfull_login;
    // }
public slots:
    void LoginPressed(void);
    void RegisterPressed(void);
    void ForgotPasswordPressed(void);
    //callback functions that get the information from the UI
    void GetLoginUsernameCallback(QString);
    void GetLoginPasswordCallback(QString);
    void GetRegisterNameCallback(QString);
    void GetRegisterUsernameCallback(QString);
    void GetRegisterPasswordCallback(QString);
    void GetRegisterRePasswordCallback(QString);
    void GetRegisterEmailCallback(QString);
    void GetRegisterGenderCallback(QString);
    void GetRegisterBirthdateCallback(QString);
    void GetForgotPasswordEmailCallback(QString);
signals:
    void SuccessfullLogin(void);

    void ShowWindow(void);
    void CloseWindow(void);
    void SetLoginStatus(QString,QString);
    void SetRegisterStatus(QString,QString);
    void SetForgotPasswordStatus(QString,QString);
    void GetLoginUsername(void);
    void GetLoginPassword(void);
    void GetRegisterName(void);
    void GetRegisterUsername(void);
    void GetRegisterPassword(void);
    void GetRegisterRePassword(void);
    void GetRegisterEmail(void);
    void GetRegisterGender(void);
    void GetRegisterBirthdate(void);
    void GetForgotPasswordEmail(void);
};

