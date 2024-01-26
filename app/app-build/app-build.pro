TEMPLATE = app
QT += quick
CONFIG += c++11

#QML resource manager here

RESOURCES += \
    qml.qrc


#C++ and header file declaration here
CPP = Source/
HPP = Header/

SOURCES += \
    Source/profilemanager.cpp \
    Source/recipe.cpp \
    Source/settingsmanager.cpp \
    main.cpp \
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
    $$HPP/date.h \
    $$HPP/fridge.h \
    $$HPP/front.hpp \
    $$HPP/ingredient.h \
    $$HPP/offer.h \
    $$HPP/temp.front.hpp \
    $$HPP/user.h \
    Header/profilemanager.h \
<<<<<<< Updated upstream
    Header/recipe.h
=======
    Header/recipe.h \
    $$HPP/Login.h \
    $$HPP/Signin.h \
    $$HPP/market.h \
    market.h \
    recipecontroller.h

INCLUDEPATH+="lib/"

DISTFILES +=


>>>>>>> Stashed changes
