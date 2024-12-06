/********************************************************************************
** Form generated from reading UI file 'loadingscreen_window.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADINGSCREEN_WINDOW_H
#define UI_LOADINGSCREEN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FadeChatLoading
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_8;
    QPushButton *AppName;
    QLabel *AppLogo;
    QLabel *LoadingText;
    QProgressBar *LoadingBar;

    void setupUi(QMainWindow *FadeChatLoading)
    {
        if (FadeChatLoading->objectName().isEmpty())
            FadeChatLoading->setObjectName("FadeChatLoading");
        FadeChatLoading->resize(370, 400);
        FadeChatLoading->setMinimumSize(QSize(370, 400));
        FadeChatLoading->setMaximumSize(QSize(370, 400));
        FadeChatLoading->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));
        centralwidget = new QWidget(FadeChatLoading);
        centralwidget->setObjectName("centralwidget");
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        AppName = new QPushButton(centralwidget);
        AppName->setObjectName("AppName");
        AppName->setEnabled(false);
        AppName->setMinimumSize(QSize(350, 25));
        AppName->setMaximumSize(QSize(350, 25));
        AppName->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_8->addWidget(AppName);

        AppLogo = new QLabel(centralwidget);
        AppLogo->setObjectName("AppLogo");
        AppLogo->setMinimumSize(QSize(350, 250));
        AppLogo->setMaximumSize(QSize(350, 250));
        AppLogo->setPixmap(QPixmap(QString::fromUtf8(":/newPrefix/images/pexels-eberhardgross-691668.jpg")));
        AppLogo->setScaledContents(true);

        verticalLayout_8->addWidget(AppLogo);

        LoadingText = new QLabel(centralwidget);
        LoadingText->setObjectName("LoadingText");
        LoadingText->setMinimumSize(QSize(350, 35));
        LoadingText->setMaximumSize(QSize(350, 35));
        LoadingText->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(LoadingText);

        LoadingBar = new QProgressBar(centralwidget);
        LoadingBar->setObjectName("LoadingBar");
        LoadingBar->setMinimumSize(QSize(350, 25));
        LoadingBar->setMaximumSize(QSize(350, 25));
        LoadingBar->setValue(0);
        LoadingBar->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(LoadingBar);


        gridLayout_3->addLayout(verticalLayout_8, 0, 0, 1, 1);

        FadeChatLoading->setCentralWidget(centralwidget);

        retranslateUi(FadeChatLoading);

        QMetaObject::connectSlotsByName(FadeChatLoading);
    } // setupUi

    void retranslateUi(QMainWindow *FadeChatLoading)
    {
        FadeChatLoading->setWindowTitle(QCoreApplication::translate("FadeChatLoading", "MainWindow", nullptr));
        AppName->setText(QCoreApplication::translate("FadeChatLoading", "Fade Chat", nullptr));
        AppLogo->setText(QString());
        LoadingText->setText(QCoreApplication::translate("FadeChatLoading", "Loading...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FadeChatLoading: public Ui_FadeChatLoading {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADINGSCREEN_WINDOW_H
