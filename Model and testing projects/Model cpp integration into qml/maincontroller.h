// maincontroller.h
#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>

class MainController : public QObject
{
    Q_OBJECT

public:
    explicit MainController(QObject *parent = nullptr);

public slots:
    void submitText(const QString &text);
};

#endif // MAINCONTROLLER_H
