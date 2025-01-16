#include "startmenu.h"

#include <thread>




using namespace std::chrono_literals;

#include <iostream>

using namespace std;

startmenu::startmenu(void)
{
    //connect login, register and forgot password slots with its signal in the UI
    connect(&UI,&startmenu_ui::LoginPressedSignal,this,&startmenu::LoginPressed,Qt::QueuedConnection);
    connect(&UI,&startmenu_ui::RegisterPressedSignal,this,&startmenu::RegisterPressed,Qt::QueuedConnection);
    connect(&UI,&startmenu_ui::ForgotPasswordPressedSignal,this,&startmenu::ForgotPasswordPressed,Qt::QueuedConnection);
    //connect the trigger signals with ui slots - 1 way
    connect(this,&startmenu::ShowWindow,&UI,&startmenu_ui::ShowWindowSlot,Qt::QueuedConnection);
    connect(this,&startmenu::CloseWindow,&UI,&startmenu_ui::CloseWindowSlot,Qt::QueuedConnection);
    connect(this,&startmenu::SetLoginStatus,&UI,&startmenu_ui::SetLoginStatusSlot,Qt::QueuedConnection);
    connect(this,&startmenu::SetRegisterStatus,&UI,&startmenu_ui::SetRegisterStatusSlot,Qt::QueuedConnection);
    connect(this,&startmenu::SetForgotPasswordStatus,&UI,&startmenu_ui::SetForgotPasswordStatusSlot,Qt::QueuedConnection);
    //connect startmenu signals with UI Slots  - 2way, first way
    connect(this,&startmenu::GetLoginUsername,&UI,&startmenu_ui::GetLoginUsernameSlot,Qt::QueuedConnection);
    connect(this,&startmenu::GetLoginPassword,&UI,&startmenu_ui::GetLoginPasswordSlot,Qt::QueuedConnection);
    connect(this,&startmenu::GetRegisterName,&UI,&startmenu_ui::GetRegisterNameSlot,Qt::QueuedConnection);
    connect(this,&startmenu::GetRegisterUsername,&UI,&startmenu_ui::GetRegisterUsernameSlot,Qt::QueuedConnection);
    connect(this,&startmenu::GetRegisterPassword,&UI,&startmenu_ui::GetRegisterPasswordSlot,Qt::QueuedConnection);
    connect(this,&startmenu::GetRegisterRePassword,&UI,&startmenu_ui::GetRegisterRePasswordSlot,Qt::QueuedConnection);
    connect(this,&startmenu::GetRegisterEmail,&UI,&startmenu_ui::GetRegisterEmailSlot,Qt::QueuedConnection);
    connect(this,&startmenu::GetRegisterGender,&UI,&startmenu_ui::GetRegisterGenderSlot,Qt::QueuedConnection);
    connect(this,&startmenu::GetRegisterBirthdate,&UI,&startmenu_ui::GetRegisterBirthdateSlot,Qt::QueuedConnection);
    connect(this,&startmenu::GetForgotPasswordEmail,&UI,&startmenu_ui::GetForgotPasswordEmailSlot,Qt::QueuedConnection);
    //connect ui signals with callback slots - 2way, second way
    connect(&UI,&startmenu_ui::GetLoginUsernameSignal,this,&startmenu::GetLoginUsernameCallback,Qt::QueuedConnection);
    connect(&UI,&startmenu_ui::GetLoginPasswordSignal,this,&startmenu::GetLoginPasswordCallback,Qt::QueuedConnection);
    connect(&UI,&startmenu_ui::GetRegisterNameSignal,this,&startmenu::GetRegisterNameCallback,Qt::QueuedConnection);
    connect(&UI,&startmenu_ui::GetRegisterUsernameSignal,this,&startmenu::GetRegisterUsernameCallback,Qt::QueuedConnection);
    connect(&UI,&startmenu_ui::GetRegisterPasswordSignal,this,&startmenu::GetRegisterPasswordCallback,Qt::QueuedConnection);
    connect(&UI,&startmenu_ui::GetRegisterRePasswordSignal,this,&startmenu::GetRegisterRePasswordCallback,Qt::QueuedConnection);
    connect(&UI,&startmenu_ui::GetRegisterEmailSignal,this,&startmenu::GetRegisterEmailCallback,Qt::QueuedConnection);
    connect(&UI,&startmenu_ui::GetRegisterGenderSignal,this,&startmenu::GetRegisterGenderCallback,Qt::QueuedConnection);
    connect(&UI,&startmenu_ui::GetRegisterBirthdateSignal,this,&startmenu::GetRegisterBirthdateCallback,Qt::QueuedConnection);
    connect(&UI,&startmenu_ui::GetForgotPasswordEmailSignal,this,&startmenu::GetForgotPasswordEmailCallback,Qt::QueuedConnection);
}


//---------------public slots
void startmenu::LoginPressed(void)
{
    start_user.clear();
    emit SetLoginStatus("",""); //clear label
    emit GetLoginUsername();
    emit GetLoginPassword();
    //this QEvent loop to process pending signals events, used with signal slots pairs
    QEventLoop slots_loop;
    slots_loop.processEvents();
    //Invaid username. contains spaces and its length is less than 8
    if(start_user.GetUsername().size() < MIN_POLICY || start_user.GetUsername().find(" ") != std::string::npos)
    {
        emit SetLoginStatus("Invalid username","color: rgb(192, 28, 40);");
        return;
    }
    //login processing
    {
        // if incorrect credentials
        // emit SetLoginStatus("Incorrect username or password","color: rgb(192, 28, 40);");
        // return;
    }
    {
        //if correct credentials
        successfull_login = true;
        return;
    }
}
void startmenu::RegisterPressed(void)
{
    start_user.clear();
    emit SetRegisterStatus("","");  //clear label
    //emit signals to get register information
    emit GetRegisterName();
    emit GetRegisterUsername();
    emit GetRegisterPassword();
    emit GetRegisterRePassword();
    emit GetRegisterEmail();
    emit GetRegisterGender();
    emit GetRegisterBirthdate();
    //this QEvent loop to process pending signals events, used with signal slots pairs
    QEventLoop slots_loop;
    slots_loop.processEvents();
    //register processing
    if(start_user.GetEnteredPassword() != start_user.GetEnteredPassword2()) //entered password are not same
    {
        emit SetRegisterStatus("Entered passwords are not the same","color: rgb(192, 28, 40);");
        return;
    }
    else if(start_user.GetEnteredPassword().size() < MIN_POLICY)   //short password
    {
        emit SetRegisterStatus("Make sure your password is greater than 8 characters","color: rgb(192, 28, 40);");
        return;
    }
    else if(start_user.GetUsername().size() < MIN_POLICY)   //username is less than minimum length
    {
        emit SetRegisterStatus("Make sure that username is greater than 8 characters","color: rgb(192, 28, 40);");
        return;
    }
    else if(start_user.GetUsername().find(" ") != std::string::npos)    //Invalid username, contains spaces
    {
        emit SetRegisterStatus("Invalid username, please remove any spaces","color: rgb(192, 28, 40);");
        return;
    }
    else if(start_user.GetGender() != "Male" && start_user.GetGender() != "Female")
    {
        emit SetRegisterStatus("Please select your gender","color: rgb(192, 28, 40);");
        return;
    }
    else if(start_user.GetEmail().find("@") == std::string::npos)    //invalid email address
    {
        emit SetRegisterStatus("Invalid email","color: rgb(192, 28, 40);");
        return;
    }
    else
    {
        {
            //if register is not successfull
        }
        {
            //if register is successfull
        }
    }
}
void startmenu::ForgotPasswordPressed(void)
{
    std::string email;
    start_user.clear();
    emit SetForgotPasswordStatus("","");    //clear label


    cout << "ServerConnection::GetIPAddress-> " << QThread::currentThread()->objectName().toStdString() << endl;

    //get email address entered
    emit GetForgotPasswordEmail();
    //this QEvent loop to process pending signals events, used with signal slots pairs
    QEventLoop slots_loop;
    slots_loop.processEvents();
    email = start_user.GetEmail();
    if(email.find("@") != std::string::npos) //if it contains @ to indicate for valid email address
    {
        emit SetForgotPasswordStatus("Email sent, please check your inbox","color: rgb(38, 162, 105);");
        //forgot password processing, creating seperate thread

        return;
    }
    else
    {
        emit SetForgotPasswordStatus("Invalid Email address","color: rgb(192, 28, 40);");
        return;
    }
}


bool startmenu::StartMenu_Task(void)
{
    StartMenuShow();
    //Idle task waiting for login status change
    while(!successfull_login)
    {
        //sleep for 250ms to not consume the CPU
        std::this_thread::sleep_for(250ms);
    }
    //StartMenuClose();
    return true;    //Login successfull
}



//Show Close menu

//callback functions that get the information from the UI
inline void startmenu::GetLoginUsernameCallback(QString usrname)
{
    start_user.SetUsername(usrname.toStdString());
}
inline void startmenu::GetLoginPasswordCallback(QString pswd)
{
    start_user.SetEnteredPassword(pswd.toStdString());
}
inline void startmenu::GetRegisterNameCallback(QString nm)
{
    start_user.SetName(nm.toStdString());
}
inline void startmenu::GetRegisterUsernameCallback(QString usrname)
{
    start_user.SetUsername(usrname.toStdString());
}
inline void startmenu::GetRegisterPasswordCallback(QString pswd)
{
    start_user.SetEnteredPassword(pswd.toStdString());
}
inline void startmenu::GetRegisterRePasswordCallback(QString pswd)
{
    start_user.SetEnteredPassword2(pswd.toStdString());
}
inline void startmenu::GetRegisterEmailCallback(QString eml)
{
    start_user.SetEmail(eml.toStdString());
}
inline void startmenu::GetRegisterGenderCallback(QString gndr)
{
    start_user.SetGender(gndr.toStdString());
}
inline void startmenu::GetRegisterBirthdateCallback(QString date)
{
    start_user.SetBirthdate(date.toStdString());
}
inline void startmenu::GetForgotPasswordEmailCallback(QString eml)
{
    start_user.SetEmail(eml.toStdString());
}

