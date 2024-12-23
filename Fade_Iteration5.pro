QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    app_main.cpp \
    loadingscreen.cpp \
    main.cpp \
    serverconnection.cpp \
    services.cpp \
    startmenu.cpp \
    startmenu_corr.cpp

HEADERS += \
    app_main.h \
    conf.h \
    loadingscreen.h \
    loadingscreen_ui.h \
    loadingscreen_window.h \
    mainmenu_ui.h \
    mainmenu_window.h \
    platform.h \
    requests.h \
    serverconnection.h \
    services.h \
    startmenu.h \
    startmenu_ui.h \
    startmenu_window.h \
    user.h \
    user_hostmachine.h

FORMS += \
    loadingscreen_window.ui \
    startmenu_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../../UserInterface/UI_Resources/icons.qrc \
    ../../UserInterface/UI_Resources/images.qrc \
    UI_Resources/images.qrc
