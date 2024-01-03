#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Header/Signin.h"
#include "Header/Login.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Signin signin;
    engine.rootContext()->setContextProperty("signin", &signin);

    Login login;
    engine.rootContext()->setContextProperty("login", &login);


    engine.load(QUrl(QStringLiteral("qrc:/QML/main.qml")));

    return app.exec();
}
