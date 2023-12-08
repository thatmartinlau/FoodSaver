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

    MsgPack mypack = MsgPack::object {
        {"key", "value"},
        {"key1", "value1"}
    };
    qDebug() << "Key: " << mypack["key"].string_value();
    std::string serialized = mypack.dump();
    qDebug() << "Serialized: " << serialized;
    std::string err;
    MsgPack repack = MsgPack::parse(serialized, err);
    qDebug() << "Repacked. error: " << err;
    qDebug() << "Key: " << repack["key"].string_value();

    qmlRegisterType<Test>("app.foodsaver", 0, 1, "Test");
    WebsocketClient wsClient; // Instantiate a WebsocketClient object with server address in config.h
    wsClient.connectToServer();

    QQmlApplicationEngine engine;

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


