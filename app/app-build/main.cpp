#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QCoreApplication>
#include <iostream>
#include "Header/date.h"
#include "Header/ingredient.h"
#include "Header/fridge.h"
#include "Header/offer.h"
#include "Header/recipe.h"
#include "Header/user.h"

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


