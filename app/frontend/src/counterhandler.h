#ifndef COUNTERHANDLER_H
#define COUNTERHANDLER_H

#endif // COUNTERHANDLER_H

// counterhandler.h

#pragma once

#include <QObject>

class CounterHandler : public QObject
{
    Q_OBJECT

public:
    explicit CounterHandler(QObject *parent = nullptr);

public slots:
    void incrementCounter();

signals:
    void counterChanged(int newCounterValue);
};
