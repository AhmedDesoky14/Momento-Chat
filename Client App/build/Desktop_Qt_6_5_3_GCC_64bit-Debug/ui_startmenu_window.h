/********************************************************************************
** Form generated from reading UI file 'startmenu_window.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTMENU_WINDOW_H
#define UI_STARTMENU_WINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QTabWidget *MainTabs;
    QWidget *LoginTab;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *RegisterText;
    QLabel *SupportText;
    QHBoxLayout *horizontalLayout;
    QPushButton *RegisterPushbutton;
    QPushButton *SupportPushButton;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *username_loginlabel;
    QLineEdit *username;
    QHBoxLayout *horizontalLayout_3;
    QLabel *password_loginlabel;
    QLineEdit *password;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *LoginButton;
    QLabel *label;
    QLabel *LoginImage;
    QWidget *RegisterTab;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *RegisterUsernameLabel;
    QLineEdit *RegisterUsername;
    QHBoxLayout *horizontalLayout_10;
    QLabel *RegisterNameLabel;
    QLineEdit *RegisterName;
    QHBoxLayout *horizontalLayout_8;
    QLabel *RegisterPasswordLabel;
    QLineEdit *RegisterPassword;
    QHBoxLayout *horizontalLayout_9;
    QLabel *RegisterReenterPasswordLabel;
    QLineEdit *RegisterReenterPassword;
    QHBoxLayout *horizontalLayout_11;
    QLabel *RegisterEmailLabel;
    QLineEdit *RegisterEmail;
    QHBoxLayout *horizontalLayout_12;
    QLabel *GenderLabel;
    QLabel *RegisterGenderLabel;
    QComboBox *RegisterGenderSelect;
    QHBoxLayout *horizontalLayout_13;
    QLabel *RegisterBirthdateLabel;
    QDateEdit *RegisterBirthDate;
    QPushButton *RegisterEnterButton;
    QLabel *RegisterStatus;
    QWidget *SupportTab;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_14;
    QLabel *ForgotPasswordLabel;
    QLineEdit *ForgotPasswordEmail;
    QHBoxLayout *horizontalLayout_15;
    QLabel *ForgotPasswordLabel_2;
    QPushButton *ForgotPasswordButton;
    QLabel *ForgotPasswordGuideLabel;
    QLabel *EmailSentStatus;
    QHBoxLayout *horizontalLayout_16;
    QLabel *ReportBugLink;
    QLabel *ReportIssueLink;
    QLabel *LoginImage_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(420, 520);
        MainWindow->setMinimumSize(QSize(420, 520));
        MainWindow->setMaximumSize(QSize(420, 520));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName("gridLayout_4");
        MainTabs = new QTabWidget(centralwidget);
        MainTabs->setObjectName("MainTabs");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainTabs->sizePolicy().hasHeightForWidth());
        MainTabs->setSizePolicy(sizePolicy);
        MainTabs->setMinimumSize(QSize(400, 500));
        MainTabs->setMaximumSize(QSize(400, 500));
        MainTabs->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);"));
        MainTabs->setIconSize(QSize(25, 25));
        LoginTab = new QWidget();
        LoginTab->setObjectName("LoginTab");
        gridLayout = new QGridLayout(LoginTab);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        RegisterText = new QLabel(LoginTab);
        RegisterText->setObjectName("RegisterText");
        RegisterText->setLineWidth(1);
        RegisterText->setAlignment(Qt::AlignCenter);
        RegisterText->setWordWrap(false);
        RegisterText->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_6->addWidget(RegisterText);

        SupportText = new QLabel(LoginTab);
        SupportText->setObjectName("SupportText");
        SupportText->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(SupportText);


        verticalLayout_4->addLayout(horizontalLayout_6);


        verticalLayout_3->addLayout(verticalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        RegisterPushbutton = new QPushButton(LoginTab);
        RegisterPushbutton->setObjectName("RegisterPushbutton");
        QIcon icon;
        icon.addFile(QString::fromUtf8("UI_Resources/icons/8687684_ic_fluent_person_add_regular_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        RegisterPushbutton->setIcon(icon);
        RegisterPushbutton->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(RegisterPushbutton);

        SupportPushButton = new QPushButton(LoginTab);
        SupportPushButton->setObjectName("SupportPushButton");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("UI_Resources/icons/8687662_ic_fluent_people_toolbox_regular_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        SupportPushButton->setIcon(icon1);
        SupportPushButton->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(SupportPushButton);


        verticalLayout_3->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_3, 3, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        username_loginlabel = new QLabel(LoginTab);
        username_loginlabel->setObjectName("username_loginlabel");
        sizePolicy.setHeightForWidth(username_loginlabel->sizePolicy().hasHeightForWidth());
        username_loginlabel->setSizePolicy(sizePolicy);
        username_loginlabel->setMinimumSize(QSize(45, 45));
        username_loginlabel->setMaximumSize(QSize(45, 45));
        username_loginlabel->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/8687666_ic_fluent_person_note_regular_icon.png);"));
        username_loginlabel->setTextFormat(Qt::RichText);

        horizontalLayout_2->addWidget(username_loginlabel);

        username = new QLineEdit(LoginTab);
        username->setObjectName("username");
        username->setMaximumSize(QSize(300, 25));
        username->setMaxLength(50);
        username->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(username);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        password_loginlabel = new QLabel(LoginTab);
        password_loginlabel->setObjectName("password_loginlabel");
        sizePolicy.setHeightForWidth(password_loginlabel->sizePolicy().hasHeightForWidth());
        password_loginlabel->setSizePolicy(sizePolicy);
        password_loginlabel->setMinimumSize(QSize(45, 45));
        password_loginlabel->setMaximumSize(QSize(45, 45));
        password_loginlabel->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/8687509_ic_fluent_key_multiple_regular_icon.png);"));
        password_loginlabel->setTextFormat(Qt::RichText);

        horizontalLayout_3->addWidget(password_loginlabel);

        password = new QLineEdit(LoginTab);
        password->setObjectName("password");
        password->setMaximumSize(QSize(300, 25));
        password->setMaxLength(50);
        password->setEchoMode(QLineEdit::Password);
        password->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(password);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        LoginButton = new QPushButton(LoginTab);
        LoginButton->setObjectName("LoginButton");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(LoginButton->sizePolicy().hasHeightForWidth());
        LoginButton->setSizePolicy(sizePolicy1);
        LoginButton->setMaximumSize(QSize(16777215, 16777215));
        LoginButton->setFlat(false);

        horizontalLayout_5->addWidget(LoginButton);

        horizontalLayout_5->setStretch(0, 1);

        verticalLayout_2->addLayout(horizontalLayout_5);


        horizontalLayout_4->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        label = new QLabel(LoginTab);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 2, 0, 1, 1);

        LoginImage = new QLabel(LoginTab);
        LoginImage->setObjectName("LoginImage");
        LoginImage->setTextFormat(Qt::RichText);
        LoginImage->setPixmap(QPixmap(QString::fromUtf8(":/newPrefix/images/pexels-eberhardgross-691668.jpg")));
        LoginImage->setScaledContents(true);

        gridLayout->addWidget(LoginImage, 0, 0, 1, 1);

        QIcon icon2;
        icon2.addFile(QString::fromUtf8("UI_Resources/icons/8687572_ic_fluent_person_arrow_right_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainTabs->addTab(LoginTab, icon2, QString());
        RegisterTab = new QWidget();
        RegisterTab->setObjectName("RegisterTab");
        gridLayout_2 = new QGridLayout(RegisterTab);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        RegisterUsernameLabel = new QLabel(RegisterTab);
        RegisterUsernameLabel->setObjectName("RegisterUsernameLabel");
        sizePolicy.setHeightForWidth(RegisterUsernameLabel->sizePolicy().hasHeightForWidth());
        RegisterUsernameLabel->setSizePolicy(sizePolicy);
        RegisterUsernameLabel->setMinimumSize(QSize(45, 45));
        RegisterUsernameLabel->setMaximumSize(QSize(45, 45));
        RegisterUsernameLabel->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/8687538_ic_fluent_person_regular_icon.png);"));
        RegisterUsernameLabel->setTextFormat(Qt::RichText);

        horizontalLayout_7->addWidget(RegisterUsernameLabel);

        RegisterUsername = new QLineEdit(RegisterTab);
        RegisterUsername->setObjectName("RegisterUsername");
        RegisterUsername->setMaximumSize(QSize(300, 25));
        RegisterUsername->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(RegisterUsername);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        RegisterNameLabel = new QLabel(RegisterTab);
        RegisterNameLabel->setObjectName("RegisterNameLabel");
        sizePolicy.setHeightForWidth(RegisterNameLabel->sizePolicy().hasHeightForWidth());
        RegisterNameLabel->setSizePolicy(sizePolicy);
        RegisterNameLabel->setMinimumSize(QSize(45, 45));
        RegisterNameLabel->setMaximumSize(QSize(45, 45));
        RegisterNameLabel->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/8687056_ic_fluent_contact_card_group_icon.png);"));
        RegisterNameLabel->setTextFormat(Qt::RichText);

        horizontalLayout_10->addWidget(RegisterNameLabel);

        RegisterName = new QLineEdit(RegisterTab);
        RegisterName->setObjectName("RegisterName");
        RegisterName->setMaximumSize(QSize(300, 25));
        RegisterName->setEchoMode(QLineEdit::Normal);
        RegisterName->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(RegisterName);


        verticalLayout_5->addLayout(horizontalLayout_10);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        RegisterPasswordLabel = new QLabel(RegisterTab);
        RegisterPasswordLabel->setObjectName("RegisterPasswordLabel");
        sizePolicy.setHeightForWidth(RegisterPasswordLabel->sizePolicy().hasHeightForWidth());
        RegisterPasswordLabel->setSizePolicy(sizePolicy);
        RegisterPasswordLabel->setMinimumSize(QSize(45, 45));
        RegisterPasswordLabel->setMaximumSize(QSize(45, 45));
        RegisterPasswordLabel->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/8687518_ic_fluent_lock_closed_regular_icon.png);"));
        RegisterPasswordLabel->setTextFormat(Qt::RichText);

        horizontalLayout_8->addWidget(RegisterPasswordLabel);

        RegisterPassword = new QLineEdit(RegisterTab);
        RegisterPassword->setObjectName("RegisterPassword");
        RegisterPassword->setMaximumSize(QSize(300, 25));
        RegisterPassword->setEchoMode(QLineEdit::Password);
        RegisterPassword->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(RegisterPassword);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        RegisterReenterPasswordLabel = new QLabel(RegisterTab);
        RegisterReenterPasswordLabel->setObjectName("RegisterReenterPasswordLabel");
        sizePolicy.setHeightForWidth(RegisterReenterPasswordLabel->sizePolicy().hasHeightForWidth());
        RegisterReenterPasswordLabel->setSizePolicy(sizePolicy);
        RegisterReenterPasswordLabel->setMinimumSize(QSize(45, 45));
        RegisterReenterPasswordLabel->setMaximumSize(QSize(45, 45));
        RegisterReenterPasswordLabel->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/8687400_ic_fluent_lock_shield_regular_icon.png);"));
        RegisterReenterPasswordLabel->setTextFormat(Qt::RichText);

        horizontalLayout_9->addWidget(RegisterReenterPasswordLabel);

        RegisterReenterPassword = new QLineEdit(RegisterTab);
        RegisterReenterPassword->setObjectName("RegisterReenterPassword");
        RegisterReenterPassword->setMaximumSize(QSize(300, 25));
        RegisterReenterPassword->setEchoMode(QLineEdit::Password);
        RegisterReenterPassword->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(RegisterReenterPassword);


        verticalLayout_5->addLayout(horizontalLayout_9);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        RegisterEmailLabel = new QLabel(RegisterTab);
        RegisterEmailLabel->setObjectName("RegisterEmailLabel");
        sizePolicy.setHeightForWidth(RegisterEmailLabel->sizePolicy().hasHeightForWidth());
        RegisterEmailLabel->setSizePolicy(sizePolicy);
        RegisterEmailLabel->setMinimumSize(QSize(45, 45));
        RegisterEmailLabel->setMaximumSize(QSize(45, 45));
        RegisterEmailLabel->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/8687459_ic_fluent_mail_regular_icon.png);"));
        RegisterEmailLabel->setTextFormat(Qt::RichText);

        horizontalLayout_11->addWidget(RegisterEmailLabel);

        RegisterEmail = new QLineEdit(RegisterTab);
        RegisterEmail->setObjectName("RegisterEmail");
        RegisterEmail->setMaximumSize(QSize(300, 25));
        RegisterEmail->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(RegisterEmail);


        verticalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        GenderLabel = new QLabel(RegisterTab);
        GenderLabel->setObjectName("GenderLabel");
        sizePolicy.setHeightForWidth(GenderLabel->sizePolicy().hasHeightForWidth());
        GenderLabel->setSizePolicy(sizePolicy);
        GenderLabel->setMinimumSize(QSize(45, 45));
        GenderLabel->setMaximumSize(QSize(45, 45));
        GenderLabel->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/male-and-female.png);"));
        GenderLabel->setTextFormat(Qt::RichText);

        horizontalLayout_12->addWidget(GenderLabel);

        RegisterGenderLabel = new QLabel(RegisterTab);
        RegisterGenderLabel->setObjectName("RegisterGenderLabel");
        RegisterGenderLabel->setMaximumSize(QSize(80, 25));
        RegisterGenderLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(RegisterGenderLabel);

        RegisterGenderSelect = new QComboBox(RegisterTab);
        RegisterGenderSelect->addItem(QString());
        RegisterGenderSelect->addItem(QString());
        RegisterGenderSelect->addItem(QString());
        RegisterGenderSelect->setObjectName("RegisterGenderSelect");
        RegisterGenderSelect->setMaximumSize(QSize(300, 25));
        RegisterGenderSelect->setLayoutDirection(Qt::LeftToRight);
        RegisterGenderSelect->setMaxVisibleItems(3);
        RegisterGenderSelect->setMaxCount(3);
        RegisterGenderSelect->setInsertPolicy(QComboBox::InsertAtBottom);

        horizontalLayout_12->addWidget(RegisterGenderSelect);


        verticalLayout_5->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        RegisterBirthdateLabel = new QLabel(RegisterTab);
        RegisterBirthdateLabel->setObjectName("RegisterBirthdateLabel");
        RegisterBirthdateLabel->setMaximumSize(QSize(150, 25));
        RegisterBirthdateLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_13->addWidget(RegisterBirthdateLabel);

        RegisterBirthDate = new QDateEdit(RegisterTab);
        RegisterBirthDate->setObjectName("RegisterBirthDate");
        RegisterBirthDate->setMaximumSize(QSize(300, 25));
        RegisterBirthDate->setAlignment(Qt::AlignCenter);
        RegisterBirthDate->setMaximumDate(QDate(2024, 12, 31));
        RegisterBirthDate->setMinimumDate(QDate(1900, 1, 1));
        RegisterBirthDate->setCurrentSection(QDateTimeEdit::DaySection);
        RegisterBirthDate->setCalendarPopup(true);
        RegisterBirthDate->setDate(QDate(2024, 1, 9));

        horizontalLayout_13->addWidget(RegisterBirthDate);


        verticalLayout_5->addLayout(horizontalLayout_13);

        RegisterEnterButton = new QPushButton(RegisterTab);
        RegisterEnterButton->setObjectName("RegisterEnterButton");

        verticalLayout_5->addWidget(RegisterEnterButton);

        RegisterStatus = new QLabel(RegisterTab);
        RegisterStatus->setObjectName("RegisterStatus");
        RegisterStatus->setMaximumSize(QSize(16777215, 25));
        RegisterStatus->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(RegisterStatus);


        gridLayout_2->addLayout(verticalLayout_5, 0, 0, 1, 1);

        MainTabs->addTab(RegisterTab, icon, QString());
        SupportTab = new QWidget();
        SupportTab->setObjectName("SupportTab");
        gridLayout_3 = new QGridLayout(SupportTab);
        gridLayout_3->setObjectName("gridLayout_3");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        ForgotPasswordLabel = new QLabel(SupportTab);
        ForgotPasswordLabel->setObjectName("ForgotPasswordLabel");
        sizePolicy.setHeightForWidth(ForgotPasswordLabel->sizePolicy().hasHeightForWidth());
        ForgotPasswordLabel->setSizePolicy(sizePolicy);
        ForgotPasswordLabel->setMinimumSize(QSize(45, 45));
        ForgotPasswordLabel->setMaximumSize(QSize(45, 45));
        ForgotPasswordLabel->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/8687526_ic_fluent_mail_alert_regular_icon.png);"));
        ForgotPasswordLabel->setTextFormat(Qt::RichText);

        horizontalLayout_14->addWidget(ForgotPasswordLabel);

        ForgotPasswordEmail = new QLineEdit(SupportTab);
        ForgotPasswordEmail->setObjectName("ForgotPasswordEmail");
        ForgotPasswordEmail->setMinimumSize(QSize(0, 25));
        ForgotPasswordEmail->setMaximumSize(QSize(300, 25));

        horizontalLayout_14->addWidget(ForgotPasswordEmail);


        verticalLayout_6->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(0);
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        ForgotPasswordLabel_2 = new QLabel(SupportTab);
        ForgotPasswordLabel_2->setObjectName("ForgotPasswordLabel_2");
        ForgotPasswordLabel_2->setMinimumSize(QSize(0, 25));
        ForgotPasswordLabel_2->setMaximumSize(QSize(175, 25));

        horizontalLayout_15->addWidget(ForgotPasswordLabel_2);

        ForgotPasswordButton = new QPushButton(SupportTab);
        ForgotPasswordButton->setObjectName("ForgotPasswordButton");
        ForgotPasswordButton->setMinimumSize(QSize(0, 25));

        horizontalLayout_15->addWidget(ForgotPasswordButton);


        verticalLayout_6->addLayout(horizontalLayout_15);

        ForgotPasswordGuideLabel = new QLabel(SupportTab);
        ForgotPasswordGuideLabel->setObjectName("ForgotPasswordGuideLabel");
        ForgotPasswordGuideLabel->setMinimumSize(QSize(0, 40));
        ForgotPasswordGuideLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(ForgotPasswordGuideLabel);

        EmailSentStatus = new QLabel(SupportTab);
        EmailSentStatus->setObjectName("EmailSentStatus");
        EmailSentStatus->setMinimumSize(QSize(0, 40));
        EmailSentStatus->setMaximumSize(QSize(16777215, 16777215));
        EmailSentStatus->setStyleSheet(QString::fromUtf8(""));
        EmailSentStatus->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(EmailSentStatus);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(80);
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        ReportBugLink = new QLabel(SupportTab);
        ReportBugLink->setObjectName("ReportBugLink");
        ReportBugLink->setTextFormat(Qt::RichText);
        ReportBugLink->setAlignment(Qt::AlignCenter);
        ReportBugLink->setOpenExternalLinks(true);

        horizontalLayout_16->addWidget(ReportBugLink);

        ReportIssueLink = new QLabel(SupportTab);
        ReportIssueLink->setObjectName("ReportIssueLink");
        ReportIssueLink->setTextFormat(Qt::RichText);
        ReportIssueLink->setAlignment(Qt::AlignCenter);
        ReportIssueLink->setOpenExternalLinks(true);

        horizontalLayout_16->addWidget(ReportIssueLink);


        verticalLayout_6->addLayout(horizontalLayout_16);


        gridLayout_3->addLayout(verticalLayout_6, 1, 0, 1, 1);

        LoginImage_2 = new QLabel(SupportTab);
        LoginImage_2->setObjectName("LoginImage_2");
        LoginImage_2->setTextFormat(Qt::RichText);
        LoginImage_2->setPixmap(QPixmap(QString::fromUtf8(":/newPrefix/images/pexels-eberhardgross-691668.jpg")));
        LoginImage_2->setScaledContents(true);

        gridLayout_3->addWidget(LoginImage_2, 0, 0, 1, 1);

        MainTabs->addTab(SupportTab, icon1, QString());

        gridLayout_4->addWidget(MainTabs, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        MainTabs->setCurrentIndex(0);
        RegisterGenderSelect->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        RegisterText->setText(QCoreApplication::translate("MainWindow", "New user ?", nullptr));
        SupportText->setText(QCoreApplication::translate("MainWindow", "Have an issue ?", nullptr));
        RegisterPushbutton->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        SupportPushButton->setText(QCoreApplication::translate("MainWindow", "Contact Support", nullptr));
        username_loginlabel->setText(QString());
        username->setPlaceholderText(QCoreApplication::translate("MainWindow", "username", nullptr));
        password_loginlabel->setText(QString());
        password->setPlaceholderText(QCoreApplication::translate("MainWindow", "password", nullptr));
        LoginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label->setText(QString());
        LoginImage->setText(QString());
        MainTabs->setTabText(MainTabs->indexOf(LoginTab), QCoreApplication::translate("MainWindow", "Login", nullptr));
        RegisterUsernameLabel->setText(QString());
        RegisterUsername->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter username", nullptr));
        RegisterNameLabel->setText(QString());
        RegisterName->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter your name", nullptr));
        RegisterPasswordLabel->setText(QString());
        RegisterPassword->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter password", nullptr));
        RegisterReenterPasswordLabel->setText(QString());
        RegisterReenterPassword->setPlaceholderText(QCoreApplication::translate("MainWindow", "Re-enter password", nullptr));
        RegisterEmailLabel->setText(QString());
        RegisterEmail->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter E-mail", nullptr));
        GenderLabel->setText(QString());
        RegisterGenderLabel->setText(QCoreApplication::translate("MainWindow", "Gender:", nullptr));
        RegisterGenderSelect->setItemText(0, QCoreApplication::translate("MainWindow", "Not selected", nullptr));
        RegisterGenderSelect->setItemText(1, QCoreApplication::translate("MainWindow", "Male", nullptr));
        RegisterGenderSelect->setItemText(2, QCoreApplication::translate("MainWindow", "Female", nullptr));

        RegisterBirthdateLabel->setText(QCoreApplication::translate("MainWindow", "Birthdate:", nullptr));
        RegisterBirthDate->setDisplayFormat(QCoreApplication::translate("MainWindow", "d/M/yyyy", nullptr));
        RegisterEnterButton->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        RegisterStatus->setText(QString());
        MainTabs->setTabText(MainTabs->indexOf(RegisterTab), QCoreApplication::translate("MainWindow", "Register", nullptr));
        ForgotPasswordLabel->setText(QString());
        ForgotPasswordEmail->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter your E-mail", nullptr));
        ForgotPasswordLabel_2->setText(QCoreApplication::translate("MainWindow", "Forgot your password ?", nullptr));
        ForgotPasswordButton->setText(QCoreApplication::translate("MainWindow", "Get temporary password", nullptr));
        ForgotPasswordGuideLabel->setText(QCoreApplication::translate("MainWindow", "You will receive a temporary password in your email\n"
"Please change it once you login", nullptr));
        EmailSentStatus->setText(QString());
        ReportBugLink->setText(QCoreApplication::translate("MainWindow", "<a href=\"http://www.google.com\">Report a Bug</a>", nullptr));
        ReportIssueLink->setText(QCoreApplication::translate("MainWindow", "<a href=\"http://www.google.com\">Report other issues</a>", nullptr));
        LoginImage_2->setText(QString());
        MainTabs->setTabText(MainTabs->indexOf(SupportTab), QCoreApplication::translate("MainWindow", "Support", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTMENU_WINDOW_H
