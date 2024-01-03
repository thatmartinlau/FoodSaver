#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Header/Signin.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Signin signin;
    engine.rootContext()->setContextProperty("signin", &signin);

    engine.load(QUrl(QStringLiteral("qrc:/QML/main.qml")));

    return app.exec();
}
