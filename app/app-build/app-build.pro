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
    Source/RecipeBook.cpp \
    Source/recipe.cpp \
    main.cpp \
    maincontroller.cpp \
    $$CPP/date.cpp \
    $$CPP/fridge.cpp \
    $$CPP/front.cpp \
    $$CPP/ingredient.cpp \
    $$CPP/link_pocco.cpp \
    $$CPP/Login.cpp \
    $$CPP/offer.cpp \
    $$CPP/temp.front.cpp \
    $$CPP/user.cpp \
    $$CPP/Signin.cpp \
    $$CPP/temp.json.cpp \
    $$CPP/profilemanager.cpp \
    $$CPP/settingsmanager.cpp \
    $$CPP/currentUser.cpp \
    $$CPP/SigninInformation.cpp \

HEADERS += \
    Header/SigninInformation.h \
    $$HPP/settingsmanager.h \
    Header/currentUser.h \
    Header/RecipeBook.h \
    Header/recipe.h \
    maincontroller.h \
    $$HPP/date.h \
    $$HPP/fridge.h \
    $$HPP/front.hpp \
    $$HPP/ingredient.h \
    $$HPP/offer.h \
    $$HPP/temp.front.hpp \
    $$HPP/user.h \
    lib/client_side_connection/server_to_backend_connection/rpc_client_side.hpp \
    Header/profilemanager.h \
    Header/recipe.h \
    $$HPP/Login.h \
    $$HPP/Signin.h
