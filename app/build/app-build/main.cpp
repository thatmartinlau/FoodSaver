#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Header/Signin.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    // Register your Signin class here
    qmlRegisterType<Signin>("com.Signin", 1, 0, "Signin");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/QML/main.qml")));

    return app.exec();
}
