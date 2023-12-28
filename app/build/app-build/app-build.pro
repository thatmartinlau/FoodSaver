TEMPLATE = app
QT += quick
CONFIG += c++11

RESOURCES += \
    qml.qrc

DISTFILES += \
    QML/LoginPage.qml \
    QML/homepage.qml \
    QML/menu1.qml \
    QML/menu2.qml \
    QML/menu3.qml \
    loginpage.qml

SOURCES += \
    backend.cpp \
    main.cpp \
    maincontroller.cpp

HEADERS += \
    backend.h \
    maincontroller.h
