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

CPP = Source/
HPP = Header/

SOURCES += \
    backend.cpp \
    main.cpp \
    maincontroller.cpp
    $$CPP/date.cpp \
    $$CPP/fridge.cpp \
    $$CPP/front.cpp \
    $$CPP/ingredient.cpp \
    $$CPP/link_pocco.cpp \
    $$CPP/offer.cpp \
    $$CPP/temp.front.cpp \
    $$CPP/temp.json.cpp \
    $$CPP/user.cpp

HEADERS += \
    backend.h \
    maincontroller.h \
    $$HPP/date.h \
    $$HPP/fridge.h \
    $$HPP/front.hpp \
    $$HPP/ingredient.h \
    $$HPP/offer.h \
    $$HPP/temp.front.hpp \
    $$HPP/user.h
