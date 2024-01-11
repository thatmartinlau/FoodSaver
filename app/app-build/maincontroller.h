#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <string>
#include <iostream>
//modif eli:
#include <QList>
#include <QMap>

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
    void submit(const QString &recipeName);
    QString gett(const int &i);
    QList<QString> search_res(const QString &entry);
    QList<QString> sorter(const QMap<QString, int> &dict);
    int getTotalLength();
    QString getJsonRTitle(const int &h);
    //modif eli: jai changé QList<QString> en QString
    //QString searchRecipes(const QString &entry, const QString &dietRestriction);
};

#endif // MAINCONTROLLER_H
