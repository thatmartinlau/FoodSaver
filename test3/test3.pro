QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        date.cpp \
        fridge.cpp \
        front.cpp \
        ingredient.cpp \
        main.cpp \
        offer.cpp \
        recipe.cpp \
        user.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    date.h \
    fridge.h \
    front.hpp \
    ingredient.h \
    offer.h \
    recipe.h \
    user.h \
    client_side_connection/server_to_backend_connection/rpc_client_side.hpp
