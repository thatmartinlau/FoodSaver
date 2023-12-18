// maincontroller.cpp
#include "maincontroller.h"
#include <QDebug>

MainController::MainController(QObject *parent) : QObject(parent)
{
}

void MainController::submitText(const QString &text)
{
    if (!text.trimmed().isEmpty()) {
        qDebug() << "User has typed:" << text << text;
    }
}
