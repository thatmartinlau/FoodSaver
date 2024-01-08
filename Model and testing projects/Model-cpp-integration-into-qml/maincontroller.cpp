// maincontroller.cpp
#include "maincontroller.h"
#include <QDebug>
#include <iostream>
#include <list>

MainController::MainController(QObject *parent) : QObject(parent)
{
}

QString MainController::submitText(const QString &text)
{
    if (!text.trimmed().isEmpty()) {
        qDebug() << "User has typed:" << text;
        return text;
    }
}

int MainController::changeTime(const QString &text)
{
    if (!text.trimmed().isEmpty()) {
        qDebug() << "User has typed time:" << text;
        QString copy = text;
        return copy.toInt();
    }
}

int MainController::submitInt(const int &time)
{
    qDebug() << "time is:" << time;
    return time + 20;
}


