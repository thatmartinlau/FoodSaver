#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "backend.h"
#include "Header/settingsmanager.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    SettingsManager settingsManager;
    engine.rootContext()->setContextProperty("settingsManager", &settingsManager);


    engine.load(QUrl(QStringLiteral("qrc:/QML/main.qml")));

    return app.exec();
}


