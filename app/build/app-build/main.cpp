#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "maincontroller.h"


int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/QML/main.qml")));

    MainController mainController;
    engine.rootContext()->setContextProperty("MainController", &mainController);


    engine.addImportPath(QCoreApplication::applicationDirPath() + "/qml");
    engine.addImportPath(":/");


    return app.exec();
}

