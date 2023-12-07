#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QWebSocket>
#include <QUrl>
#include <QtCore/QDebug>
#include <QQmlContext>
#include <iostream>
#include "test.h"
#include "websocketclient.h"

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

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


