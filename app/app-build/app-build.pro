TEMPLATE = app
QT += quick
CONFIG += c++11
CONFIG += console

#QML resource manager here

RESOURCES += \
    qml.qrc


#C++ and header file declaration here


CPP = Source/
HPP = Header/

SOURCES += \
    Source/profilemanager.cpp \
    Source/settingsmanager.cpp \
    Source/RecipeBook.cpp \
    Source/recipe.cpp \
    #backend.cpp \
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
    $$HPP/settingsmanager.h \
    Header/RecipeBook.h \
    Header/recipe.h \
    backend.h \
    maincontroller.h \
    $$HPP/date.h \
    $$HPP/fridge.h \
    $$HPP/front.hpp \
    $$HPP/ingredient.h \
    $$HPP/offer.h \
    $$HPP/temp.front.hpp \
    $$HPP/user.h \
    Header/profilemanager.h
