#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>

class MainController : public QObject
{
    Q_OBJECT

public:
    explicit MainController(QObject *parent = nullptr);

public slots:
    QString submitAll(const QString &recipeName, const QString &diet, const QString &hours, const QString &minutes, const QString &ingredient1, const QString &instruction1);
    QString submitText(const QString &text);
    double changeTime(const QString &text);
    int submitInt(const int &time);
};

#endif // MAINCONTROLLER_H
