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

#include "Header/Signin.h"
#include "Header/Login.h"
#include "Header/SigninInformation.h"

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

    Signin signin;
    engine.rootContext()->setContextProperty("signin", &signin);

    Login login;
    engine.rootContext()->setContextProperty("login", &login);

    SigninInfo signinInfo;
    engine.rootContext()->setContextProperty("signinInfo", &signinInfo);

    engine.load(QUrl(QStringLiteral("qrc:/QML/main.qml")));

    return app.exec();
}
