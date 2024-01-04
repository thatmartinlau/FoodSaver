TEMPLATE = app
QT += quick
CONFIG += c++11
CONFIG += console

RESOURCES += \
    qml.qrc

DISTFILES += \
    Jason/Recipes.json \
    QML/LoginPage.qml \
    QML/homepage.qml \
    QML/menu1.qml \
    QML/menu2.qml \
    QML/menu3.qml \
    loginpage.qml

CPP = Source/
HPP = Header/

SOURCES += \
    Source/RecipeBook.cpp \
    backend.cpp \
    main.cpp \
    maincontroller.cpp \
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
    Header/RecipeBook.h \
    backend.h \
    maincontroller.h \
    $$HPP/date.h \
    $$HPP/fridge.h \
    $$HPP/front.hpp \
    $$HPP/ingredient.h \
    $$HPP/offer.h \
    $$HPP/temp.front.hpp \
    $$HPP/user.h
