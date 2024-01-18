#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Header/settingsmanager.h"
#include "Header/profilemanager.h"
#include "Header/fridge.h"
#include "Header/user.h"
#include "maincontroller.h"


int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    ProfileManager profileManager;
    engine.rootContext()->setContextProperty("profileManager", &profileManager);

    SettingsManager settingsManager;
    engine.rootContext()->setContextProperty("settingsManager", &settingsManager);

    //User user;
    //engine.rootContext()->setContextProperty("user", &user);

    //Fridge fridge;
    //engine.rootContext()->setContextProperty("fridge", &fridge);


    MainController mainController;
    engine.rootContext()->setContextProperty("MainController", &mainController);


    engine.addImportPath(QCoreApplication::applicationDirPath() + "/qml");
    engine.addImportPath(":/");


    engine.load(QUrl(QStringLiteral("qrc:/QML/main.qml")));

    return app.exec();
}

