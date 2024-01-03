#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Header/settingsmanager.h"
#include "Header/profilemanager.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    ProfileManager profileManager;
    engine.rootContext()->setContextProperty("profileManager", &profileManager);

    SettingsManager settingsManager;
    engine.rootContext()->setContextProperty("settingsManager", &settingsManager);


    engine.load(QUrl(QStringLiteral("qrc:/QML/main.qml")));

    return app.exec();
}


