#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>

class MainController : public QObject
{
    Q_OBJECT

public:
    explicit MainController(QObject *parent = nullptr);

public slots:
    QString submitText(const QString &text);
    double changeTime(const QString &text);
    int submitInt(const int &time);
};

#endif // MAINCONTROLLER_H
