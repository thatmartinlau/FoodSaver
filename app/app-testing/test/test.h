#ifndef TEST_TEST_H
#define TEST_TEST_H

#include <QObject>
#include <QDebug>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);

public slots: //Functions declared in response to signals
    void clickTest();

signals:

};

#endif // TEST_H
