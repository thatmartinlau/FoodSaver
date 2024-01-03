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

double MainController::changeTime(const QString &text)
{
    QStringList list1 = text.split(u'h');
    if (!list1[0].trimmed().isEmpty() && !list1[1].trimmed().isEmpty()) {
        qDebug() << "User has typed time:" << text;
        QString copyHrs = list1[0];
        QString copyMin = list1[1];
        int res[2] = {copyHrs.toInt(), copyMin.toInt()};

        double decimal = (double)res[1]/(double)60;
        double time = (double)res[0] + decimal;
        return time;
    }
}

int MainController::submitInt(const int &time)
{
    qDebug() << "time is:" << time;
    return time + 20;
}

QString MainController::submitAll(const QString &recipeName, const QString &diet, const QString &hours, const QString &minutes, const QString &ingredient1, const QString &instruction1)
{
    //qDebug() << "name" << recipeName << "diet" << diet<< "ingr" << ingredient1<< "instr" << instruction1 << "hours"<< hours << "minutes" << minutes;
    return recipeName+diet+hours+minutes+ingredient1+instruction1;
}
