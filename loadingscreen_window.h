/********************************************************************************
** Form generated from reading UI file 'loadingscreen_window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef LOADINGSCREEN_WINDOW_H
#define LOADINGSCREEN_WINDOW_H

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

class Ui_LoadingScreenWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_8;
    QPushButton *AppName;
    QLabel *AppLogo;
    QLabel *LoadingText;
    QProgressBar *LoadingBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(370, 400);
        MainWindow->setMinimumSize(QSize(370, 400));
        MainWindow->setMaximumSize(QSize(370, 400));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        AppName = new QPushButton(centralwidget);
        AppName->setObjectName(QString::fromUtf8("AppName"));
        AppName->setEnabled(false);
        AppName->setMinimumSize(QSize(350, 25));
        AppName->setMaximumSize(QSize(350, 25));
        AppName->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_8->addWidget(AppName);

        AppLogo = new QLabel(centralwidget);
        AppLogo->setObjectName(QString::fromUtf8("AppLogo"));
        AppLogo->setMinimumSize(QSize(350, 250));
        AppLogo->setMaximumSize(QSize(350, 250));
        AppLogo->setPixmap(QPixmap(QString::fromUtf8(":/newPrefix/images/pexels-eberhardgross-691668.jpg")));
        AppLogo->setScaledContents(true);

        verticalLayout_8->addWidget(AppLogo);

        LoadingText = new QLabel(centralwidget);
        LoadingText->setObjectName(QString::fromUtf8("LoadingText"));
        LoadingText->setMinimumSize(QSize(350, 35));
        LoadingText->setMaximumSize(QSize(350, 35));
        LoadingText->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(LoadingText);

        LoadingBar = new QProgressBar(centralwidget);
        LoadingBar->setObjectName(QString::fromUtf8("LoadingBar"));
        LoadingBar->setMinimumSize(QSize(350, 25));
        LoadingBar->setMaximumSize(QSize(350, 25));
        LoadingBar->setValue(0);
        LoadingBar->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(LoadingBar);


        gridLayout_3->addLayout(verticalLayout_8, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        AppName->setText(QCoreApplication::translate("MainWindow", "Fade Chat", nullptr));
        AppLogo->setText(QString());
        LoadingText->setText(QCoreApplication::translate("MainWindow", "Loading...", nullptr));
    } // retranslateUi

};

namespace UI {
    class LoadingScreenWindow: public Ui_LoadingScreenWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // LOADINGSCREEN_WINDOW_H
