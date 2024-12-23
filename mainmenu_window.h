/********************************************************************************
** Form generated from reading UI file 'mainmenu_window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINMENU_WINDOW_H
#define MAINMENU_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenuWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QTabWidget *MainMenuTabs;
    QWidget *ConnectTab;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_9;
    QLabel *Name;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_8;
    QLabel *UserStatusLabel;
    QLabel *UserStatus;
    QLabel *ChatModeStatus;
    QLabel *ChatMode;
    QLabel *BackgroundImage;
    QFrame *blocklistline_3;
    QLabel *ConnectStatusLabel;
    QLineEdit *usernameentered;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *ConnectButton;
    QPushButton *CheckButton;
    QHBoxLayout *horizontalLayout;
    QLabel *ReportIssueLink;
    QLabel *ReportBugLink;
    QWidget *SettingsTab;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_3;
    QLabel *ChangePasswordLabel;
    QLineEdit *CurrentPassword;
    QLineEdit *NewPassword;
    QLineEdit *NewPassword2;
    QLabel *ChangePasswordStatusLabel;
    QPushButton *ChangePasswordButton;
    QFrame *blocklistline_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QLabel *SetTimeoutStatus;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *TimeoutButton;
    QSpinBox *TimeoutSpinBox;
    QFrame *blocklistline_4;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_6;
    QLabel *VisualizationLabel;
    QComboBox *VisualizationBox;
    QFrame *line;
    QVBoxLayout *verticalLayout_4;
    QLabel *OnlineStatusLabel;
    QComboBox *OnlineStatusBox;
    QFrame *line_2;
    QVBoxLayout *verticalLayout;
    QLabel *VisualizationLabel_2;
    QComboBox *comboBox;
    QWidget *BlockListTab;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QListWidget *BlockList;
    QFrame *blocklistline;
    QLabel *BlockStatusLabel;
    QLabel *BlockGuideLabel;
    QLineEdit *blockusername;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *BlockButton;
    QPushButton *UnblockButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(520, 520);
        MainWindow->setMinimumSize(QSize(520, 520));
        MainWindow->setMaximumSize(QSize(520, 520));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(520, 520));
        centralwidget->setMaximumSize(QSize(520, 520));
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        MainMenuTabs = new QTabWidget(centralwidget);
        MainMenuTabs->setObjectName(QString::fromUtf8("MainMenuTabs"));
        MainMenuTabs->setMinimumSize(QSize(500, 500));
        MainMenuTabs->setMaximumSize(QSize(500, 500));
        MainMenuTabs->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);"));
        MainMenuTabs->setIconSize(QSize(25, 25));
        ConnectTab = new QWidget();
        ConnectTab->setObjectName(QString::fromUtf8("ConnectTab"));
        gridLayout = new QGridLayout(ConnectTab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        Name = new QLabel(ConnectTab);
        Name->setObjectName(QString::fromUtf8("Name"));

        verticalLayout_9->addWidget(Name);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        UserStatusLabel = new QLabel(ConnectTab);
        UserStatusLabel->setObjectName(QString::fromUtf8("UserStatusLabel"));
        UserStatusLabel->setMaximumSize(QSize(55, 16777215));

        horizontalLayout_8->addWidget(UserStatusLabel);

        UserStatus = new QLabel(ConnectTab);
        UserStatus->setObjectName(QString::fromUtf8("UserStatus"));

        horizontalLayout_8->addWidget(UserStatus);

        ChatModeStatus = new QLabel(ConnectTab);
        ChatModeStatus->setObjectName(QString::fromUtf8("ChatModeStatus"));
        ChatModeStatus->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_8->addWidget(ChatModeStatus);

        ChatMode = new QLabel(ConnectTab);
        ChatMode->setObjectName(QString::fromUtf8("ChatMode"));

        horizontalLayout_8->addWidget(ChatMode);


        verticalLayout_8->addLayout(horizontalLayout_8);

        BackgroundImage = new QLabel(ConnectTab);
        BackgroundImage->setObjectName(QString::fromUtf8("BackgroundImage"));
        BackgroundImage->setMinimumSize(QSize(250, 250));
        BackgroundImage->setMaximumSize(QSize(1000, 1000));
        BackgroundImage->setPixmap(QPixmap(QString::fromUtf8(":/newPrefix/images/pexels-eberhardgross-691668.jpg")));
        BackgroundImage->setScaledContents(true);

        verticalLayout_8->addWidget(BackgroundImage);

        blocklistline_3 = new QFrame(ConnectTab);
        blocklistline_3->setObjectName(QString::fromUtf8("blocklistline_3"));
        blocklistline_3->setWindowModality(Qt::NonModal);
        blocklistline_3->setFrameShape(QFrame::HLine);
        blocklistline_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(blocklistline_3);

        ConnectStatusLabel = new QLabel(ConnectTab);
        ConnectStatusLabel->setObjectName(QString::fromUtf8("ConnectStatusLabel"));
        ConnectStatusLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(ConnectStatusLabel);

        usernameentered = new QLineEdit(ConnectTab);
        usernameentered->setObjectName(QString::fromUtf8("usernameentered"));
        usernameentered->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(usernameentered);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        ConnectButton = new QPushButton(ConnectTab);
        ConnectButton->setObjectName(QString::fromUtf8("ConnectButton"));

        horizontalLayout_7->addWidget(ConnectButton);

        CheckButton = new QPushButton(ConnectTab);
        CheckButton->setObjectName(QString::fromUtf8("CheckButton"));

        horizontalLayout_7->addWidget(CheckButton);


        verticalLayout_8->addLayout(horizontalLayout_7);


        verticalLayout_9->addLayout(verticalLayout_8);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ReportIssueLink = new QLabel(ConnectTab);
        ReportIssueLink->setObjectName(QString::fromUtf8("ReportIssueLink"));
        ReportIssueLink->setTextFormat(Qt::RichText);
        ReportIssueLink->setAlignment(Qt::AlignCenter);
        ReportIssueLink->setOpenExternalLinks(true);

        horizontalLayout->addWidget(ReportIssueLink);

        ReportBugLink = new QLabel(ConnectTab);
        ReportBugLink->setObjectName(QString::fromUtf8("ReportBugLink"));
        ReportBugLink->setStyleSheet(QString::fromUtf8(""));
        ReportBugLink->setTextFormat(Qt::RichText);
        ReportBugLink->setAlignment(Qt::AlignCenter);
        ReportBugLink->setOpenExternalLinks(true);

        horizontalLayout->addWidget(ReportBugLink);


        verticalLayout_9->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_9, 0, 0, 1, 1);

        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/8687534_ic_fluent_person_mail_regular_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainMenuTabs->addTab(ConnectTab, icon, QString());
        SettingsTab = new QWidget();
        SettingsTab->setObjectName(QString::fromUtf8("SettingsTab"));
        gridLayout_3 = new QGridLayout(SettingsTab);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        ChangePasswordLabel = new QLabel(SettingsTab);
        ChangePasswordLabel->setObjectName(QString::fromUtf8("ChangePasswordLabel"));
        ChangePasswordLabel->setMaximumSize(QSize(16777215, 30));
        ChangePasswordLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(ChangePasswordLabel);

        CurrentPassword = new QLineEdit(SettingsTab);
        CurrentPassword->setObjectName(QString::fromUtf8("CurrentPassword"));
        CurrentPassword->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(CurrentPassword);

        NewPassword = new QLineEdit(SettingsTab);
        NewPassword->setObjectName(QString::fromUtf8("NewPassword"));
        NewPassword->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(NewPassword);

        NewPassword2 = new QLineEdit(SettingsTab);
        NewPassword2->setObjectName(QString::fromUtf8("NewPassword2"));
        NewPassword2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(NewPassword2);

        ChangePasswordStatusLabel = new QLabel(SettingsTab);
        ChangePasswordStatusLabel->setObjectName(QString::fromUtf8("ChangePasswordStatusLabel"));
        ChangePasswordStatusLabel->setMaximumSize(QSize(16777215, 30));
        ChangePasswordStatusLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(ChangePasswordStatusLabel);

        ChangePasswordButton = new QPushButton(SettingsTab);
        ChangePasswordButton->setObjectName(QString::fromUtf8("ChangePasswordButton"));

        verticalLayout_3->addWidget(ChangePasswordButton);

        blocklistline_2 = new QFrame(SettingsTab);
        blocklistline_2->setObjectName(QString::fromUtf8("blocklistline_2"));
        blocklistline_2->setWindowModality(Qt::NonModal);
        blocklistline_2->setFrameShape(QFrame::HLine);
        blocklistline_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(blocklistline_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_4 = new QLabel(SettingsTab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_4);

        SetTimeoutStatus = new QLabel(SettingsTab);
        SetTimeoutStatus->setObjectName(QString::fromUtf8("SetTimeoutStatus"));
        SetTimeoutStatus->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(SetTimeoutStatus);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        TimeoutButton = new QPushButton(SettingsTab);
        TimeoutButton->setObjectName(QString::fromUtf8("TimeoutButton"));

        horizontalLayout_4->addWidget(TimeoutButton);

        TimeoutSpinBox = new QSpinBox(SettingsTab);
        TimeoutSpinBox->setObjectName(QString::fromUtf8("TimeoutSpinBox"));

        horizontalLayout_4->addWidget(TimeoutSpinBox);


        verticalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(verticalLayout_5);

        blocklistline_4 = new QFrame(SettingsTab);
        blocklistline_4->setObjectName(QString::fromUtf8("blocklistline_4"));
        blocklistline_4->setWindowModality(Qt::NonModal);
        blocklistline_4->setFrameShape(QFrame::HLine);
        blocklistline_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(blocklistline_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        VisualizationLabel = new QLabel(SettingsTab);
        VisualizationLabel->setObjectName(QString::fromUtf8("VisualizationLabel"));
        VisualizationLabel->setMaximumSize(QSize(16777215, 35));
        VisualizationLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(VisualizationLabel);

        VisualizationBox = new QComboBox(SettingsTab);
        VisualizationBox->addItem(QString());
        VisualizationBox->addItem(QString());
        VisualizationBox->setObjectName(QString::fromUtf8("VisualizationBox"));

        verticalLayout_6->addWidget(VisualizationBox);


        horizontalLayout_6->addLayout(verticalLayout_6);

        line = new QFrame(SettingsTab);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_6->addWidget(line);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        OnlineStatusLabel = new QLabel(SettingsTab);
        OnlineStatusLabel->setObjectName(QString::fromUtf8("OnlineStatusLabel"));
        OnlineStatusLabel->setMaximumSize(QSize(16777215, 35));
        OnlineStatusLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(OnlineStatusLabel);

        OnlineStatusBox = new QComboBox(SettingsTab);
        OnlineStatusBox->addItem(QString());
        OnlineStatusBox->addItem(QString());
        OnlineStatusBox->addItem(QString());
        OnlineStatusBox->addItem(QString());
        OnlineStatusBox->setObjectName(QString::fromUtf8("OnlineStatusBox"));
        OnlineStatusBox->setEditable(false);

        verticalLayout_4->addWidget(OnlineStatusBox);


        horizontalLayout_6->addLayout(verticalLayout_4);

        line_2 = new QFrame(SettingsTab);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_6->addWidget(line_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        VisualizationLabel_2 = new QLabel(SettingsTab);
        VisualizationLabel_2->setObjectName(QString::fromUtf8("VisualizationLabel_2"));
        VisualizationLabel_2->setMaximumSize(QSize(16777215, 35));
        VisualizationLabel_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(VisualizationLabel_2);

        comboBox = new QComboBox(SettingsTab);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);


        horizontalLayout_6->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_6);


        verticalLayout_7->addLayout(verticalLayout_3);


        gridLayout_3->addLayout(verticalLayout_7, 0, 0, 1, 1);

        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/8687586_ic_fluent_person_settings_regular_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainMenuTabs->addTab(SettingsTab, icon1, QString());
        BlockListTab = new QWidget();
        BlockListTab->setObjectName(QString::fromUtf8("BlockListTab"));
        gridLayout_2 = new QGridLayout(BlockListTab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        BlockList = new QListWidget(BlockListTab);
        BlockList->setObjectName(QString::fromUtf8("BlockList"));
        BlockList->setEnabled(true);
        QPalette palette;
        QBrush brush(QColor(222, 221, 218, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        BlockList->setPalette(palette);
        BlockList->setStyleSheet(QString::fromUtf8(""));
        BlockList->setFrameShadow(QFrame::Sunken);
        BlockList->setLineWidth(1);
        BlockList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        BlockList->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        BlockList->setEditTriggers(QAbstractItemView::AllEditTriggers);
        BlockList->setSelectionMode(QAbstractItemView::NoSelection);
        BlockList->setTextElideMode(Qt::ElideRight);
        BlockList->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
        BlockList->setMovement(QListView::Static);
        BlockList->setFlow(QListView::TopToBottom);
        BlockList->setProperty("isWrapping", QVariant(false));
        BlockList->setLayoutMode(QListView::SinglePass);
        BlockList->setViewMode(QListView::ListMode);
        BlockList->setBatchSize(5000);
        BlockList->setSortingEnabled(true);

        verticalLayout_2->addWidget(BlockList);

        blocklistline = new QFrame(BlockListTab);
        blocklistline->setObjectName(QString::fromUtf8("blocklistline"));
        blocklistline->setWindowModality(Qt::NonModal);
        blocklistline->setFrameShape(QFrame::HLine);
        blocklistline->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(blocklistline);

        BlockStatusLabel = new QLabel(BlockListTab);
        BlockStatusLabel->setObjectName(QString::fromUtf8("BlockStatusLabel"));
        BlockStatusLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(BlockStatusLabel);

        BlockGuideLabel = new QLabel(BlockListTab);
        BlockGuideLabel->setObjectName(QString::fromUtf8("BlockGuideLabel"));
        BlockGuideLabel->setEnabled(true);
        BlockGuideLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(BlockGuideLabel);

        blockusername = new QLineEdit(BlockListTab);
        blockusername->setObjectName(QString::fromUtf8("blockusername"));
        blockusername->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(blockusername);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        BlockButton = new QPushButton(BlockListTab);
        BlockButton->setObjectName(QString::fromUtf8("BlockButton"));
        BlockButton->setStyleSheet(QString::fromUtf8("background-color: rgb(246, 97, 81);"));

        horizontalLayout_2->addWidget(BlockButton);

        UnblockButton = new QPushButton(BlockListTab);
        UnblockButton->setObjectName(QString::fromUtf8("UnblockButton"));
        UnblockButton->setStyleSheet(QString::fromUtf8("background-color: rgb(143, 240, 164);"));

        horizontalLayout_2->addWidget(UnblockButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);

        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/8687632_ic_fluent_people_prohibited_regular_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainMenuTabs->addTab(BlockListTab, icon2, QString());

        gridLayout_4->addWidget(MainMenuTabs, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        MainMenuTabs->setCurrentIndex(0);
        VisualizationBox->setCurrentIndex(0);
        BlockList->setCurrentRow(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Name->setText(QString());
        UserStatusLabel->setText(QCoreApplication::translate("MainWindow", "Status: ", nullptr));
        UserStatus->setText(QString());
        ChatModeStatus->setText(QCoreApplication::translate("MainWindow", "Chat Mode: ", nullptr));
        ChatMode->setText(QString());
        BackgroundImage->setText(QString());
        ConnectStatusLabel->setText(QString());
        usernameentered->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter username", nullptr));
        ConnectButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        CheckButton->setText(QCoreApplication::translate("MainWindow", "Check Availability", nullptr));
        ReportIssueLink->setText(QCoreApplication::translate("MainWindow", "<a href=\"http://www.google.com\">Report other issues</a>", nullptr));
        ReportBugLink->setText(QCoreApplication::translate("MainWindow", "<a href=\"http://www.google.com\">Report a Bug</a>", nullptr));
        MainMenuTabs->setTabText(MainMenuTabs->indexOf(ConnectTab), QCoreApplication::translate("MainWindow", "Connect", nullptr));
        ChangePasswordLabel->setText(QCoreApplication::translate("MainWindow", "Change Password", nullptr));
        CurrentPassword->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter current password", nullptr));
        NewPassword->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter new password", nullptr));
        NewPassword2->setText(QString());
        NewPassword2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Re-enter new password", nullptr));
        ChangePasswordStatusLabel->setText(QString());
        ChangePasswordButton->setText(QCoreApplication::translate("MainWindow", "Change Password", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Set non-text messages\n"
"preview timeout in seconds", nullptr));
        SetTimeoutStatus->setText(QString());
        TimeoutButton->setText(QCoreApplication::translate("MainWindow", "Set timeout", nullptr));
        VisualizationLabel->setText(QCoreApplication::translate("MainWindow", "Visualization", nullptr));
        VisualizationBox->setItemText(0, QCoreApplication::translate("MainWindow", "Bright Mode", nullptr));
        VisualizationBox->setItemText(1, QCoreApplication::translate("MainWindow", "Dark Mode", nullptr));

        OnlineStatusLabel->setText(QCoreApplication::translate("MainWindow", "Online Status", nullptr));
        OnlineStatusBox->setItemText(0, QCoreApplication::translate("MainWindow", "Online", nullptr));
        OnlineStatusBox->setItemText(1, QCoreApplication::translate("MainWindow", "Away", nullptr));
        OnlineStatusBox->setItemText(2, QCoreApplication::translate("MainWindow", "Invisible", nullptr));
        OnlineStatusBox->setItemText(3, QCoreApplication::translate("MainWindow", "Do Not Disturb", nullptr));

        VisualizationLabel_2->setText(QCoreApplication::translate("MainWindow", "Preferred Chat modes", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "One Time Chat", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Saved Chat", nullptr));

        MainMenuTabs->setTabText(MainMenuTabs->indexOf(SettingsTab), QCoreApplication::translate("MainWindow", "Settings", nullptr));
        BlockStatusLabel->setText(QString());
        BlockGuideLabel->setText(QCoreApplication::translate("MainWindow", "Enter username", nullptr));
        blockusername->setText(QString());
        blockusername->setPlaceholderText(QString());
        BlockButton->setText(QCoreApplication::translate("MainWindow", "Block", nullptr));
        UnblockButton->setText(QCoreApplication::translate("MainWindow", "Unblock", nullptr));
        MainMenuTabs->setTabText(MainMenuTabs->indexOf(BlockListTab), QCoreApplication::translate("MainWindow", "Block List", nullptr));
    } // retranslateUi

};

namespace UI {
    class MainMenuWindow: public Ui_MainMenuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINMENU_WINDOW_H
