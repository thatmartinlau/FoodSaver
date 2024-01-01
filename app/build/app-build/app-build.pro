TEMPLATE = app
QT += quick
CONFIG += c++11

RESOURCES += \
    qml.qrc

DISTFILES += \
    QML/LoginPage.qml \
    QML/SigninPage.qml \
    QML/homepage.qml \
    QML/menu1.qml \
    QML/menu2.qml \
    QML/menu3.qml \
    loginpage.qml

SOURCES += \
    Login.cpp \
    Signin.cpp \
    backend.cpp \
    main.cpp

HEADERS += \
    Login.h \
    Signin.h \
    backend.h
