TEMPLATE = app
QT += quick
CONFIG += c++11
RESOURCES += qml.qrc \
    qml.qrc
SOURCES += \
    Backend.cpp \
    main.cpp

DISTFILES += \
    HomePage.qml \
    LoginPage.qml \
    Menu1.qml \
    Menu2.qml \
    Menu3.qml \
    main.qml

HEADERS += \
    Backend.h
