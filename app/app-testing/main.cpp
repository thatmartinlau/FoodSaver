#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QWebSocket>
#include <QUrl>
#include <QtCore/QDebug>
#include <QQmlContext>
#include <iostream>

// Import internal header files
#include "test/test.h"
#include "websocketclient/websocketclient.h"

// Import external dependencies
#include "dependencies/msgpack11/msgpack11.hpp"
using namespace msgpack11;


int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    // Register C++ components in QML
    qmlRegisterType<Test>("app.foodsaver", 0, 1, "Test");

    QQmlApplicationEngine engine;

    // Instantiate a WebsocketClient object with server address in config.h, with parameter QMLEngine by reference
    WebsocketClient wsClient;
    wsClient.connectToServer(); //Autoconnect

    engine.rootContext()->setContextProperty("wsClient", &wsClient);

    const QUrl url(u"qrc:/app/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);

    engine.load(url);


    return app.exec();
}


