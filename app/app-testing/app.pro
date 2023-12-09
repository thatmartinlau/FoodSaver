QT += quick websockets

# Some measurement to fix the bugs caused by different Openssl versions of Qt & Android SDK (1.1 vs 3.x)
# If it doesnt work for you check ur openssl folder and the path of the libs but dont edit s.v.p.
# Dont touch it if it works fine on your android build...
android {
    message(ANDROID OPENSSL ADDITIONAL LIBRARIES LOADED)
    LIBS += $$ANDROID_SDK_ROOT/android_openssl/ssl_1.1/arm64-v8a/libssl_1_1.so
    LIBS += $$ANDROID_SDK_ROOT/android_openssl/ssl_1.1/arm64-v8a/libcrypto_1_1.so
    ANDROID_EXTRA_LIBS += $$ANDROID_SDK_ROOT/android_openssl/ssl_1.1/arm64-v8a/libssl_1_1.so
    ANDROID_EXTRA_LIBS += $$ANDROID_SDK_ROOT/android_openssl/ssl_1.1/arm64-v8a/libcrypto_1_1.so
    LIBS += $$ANDROID_SDK_ROOT/android_openssl/ssl_3/arm64-v8a/libssl_3.so
    LIBS += $$ANDROID_SDK_ROOT/android_openssl/ssl_3/arm64-v8a/libcrypto_3.so
    ANDROID_EXTRA_LIBS += $$ANDROID_SDK_ROOT/android_openssl/ssl_3/arm64-v8a/libssl_3.so
    ANDROID_EXTRA_LIBS += $$ANDROID_SDK_ROOT/android_openssl/ssl_3/arm64-v8a/libcrypto_3.so
}

# Disable qDebug() for release builds
CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT

SOURCES += \
        main.cpp \
        test/test.cpp \
        websocketclient/websocketclient.cpp

resources.files = main.qml qml_components/Fridge.qml qml_components/Share.qml qml_components/Account.qml login.qml
resources.prefix = /$${TARGET}
RESOURCES += resources

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = qml_components

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH = qml_components

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    login.qml \
    qml_components/Fridge.qml \
    qml_components/Account.qml \
    qml_components/Share.qml \
    login.qml

HEADERS += \
    config.h \
    test/test.h \
    websocketclient/websocketclient.h

# Import msgpack11 dependency
HEADERS += dependencies/msgpack11/msgpack11.hpp
SOURCES += dependencies/msgpack11/msgpack11.cpp

