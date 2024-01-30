#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QCoreApplication>
#include <iostream>
#include "date.h"
#include "ingredient.h"
#include "fridge.h"
#include "offer.h"
#include "recipe.h"
#include "user.h"

#include "settingsmanager.h"
#include "profilemanager.h"
#include "fridgemanager.h"
#include "Signin.h"
#include "Login.h"
#include "SigninInformation.h"

#include "recipecontroller.h"


int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    ProfileManager profileManager;
    engine.rootContext()->setContextProperty("profileManager", &profileManager);

    SettingsManager settingsManager;
    engine.rootContext()->setContextProperty("settingsManager", &settingsManager);

    //User user;
    //engine.rootContext()->setContextProperty("user", &user);

    FridgeManager fridge;
    engine.rootContext()->setContextProperty("fridgemanager", &fridge);

    Signin signin;
    engine.rootContext()->setContextProperty("signin", &signin);

    Login login;
    engine.rootContext()->setContextProperty("login", &login);

    SigninInfo signinInfo;
    engine.rootContext()->setContextProperty("signinInfo", &signinInfo);

    RecipeController recipeController;
    engine.rootContext()->setContextProperty("RecipeController", &recipeController);

    engine.addImportPath(QCoreApplication::applicationDirPath() + "/qml");
    engine.addImportPath(":/");

    engine.load(QUrl(QStringLiteral("qrc:/QML/main.qml")));

    return app.exec();
}

