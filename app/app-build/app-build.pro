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
    Source/SigninInformation.cpp \
    Source/currentUser.cpp \
    main.cpp \
    $$CPP/date.cpp \
    $$CPP/fridge.cpp \
    $$CPP/front.cpp \
    $$CPP/ingredient.cpp \
    $$CPP/link_pocco.cpp \
    $$CPP/offer.cpp \
    $$CPP/temp.front.cpp \
    $$CPP/user.cpp

HEADERS += \
    $$HPP/settingsmanager.h \
    $$CPP/temp.json.cpp \
    $$CPP/user.cpp \
    $$CPP/Login.cpp \
    $$CPP/Signin.cpp


HEADERS += \
    Header/SigninInformation.h \
    Header/currentUser.h \
    $$HPP/date.h \
    $$HPP/fridge.h \
    $$HPP/front.hpp \
    $$HPP/ingredient.h \
    $$HPP/offer.h \
    $$HPP/temp.front.hpp \
    $$HPP/user.h \
    lib/client_side_connection/server_to_backend_connection/rpc_client_side.hpp \
    Header/profilemanager.h \
    Header/recipe.h
    $$HPP/Login.h \
    $$HPP/Signin.h
