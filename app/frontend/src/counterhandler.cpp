// counterhandler.cpp

#include "counterhandler.h"

CounterHandler::CounterHandler(QObject *parent)
    : QObject(parent)
{
}

void CounterHandler::incrementCounter()
{
    static int counter = 0;
    ++counter;

    // Emit the signal to notify QML about the new counter value
    emit counterChanged(counter);
}
