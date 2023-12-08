// As its name suggests, this is a testing playground...
#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{

}

void Test::clickTest() {
    qDebug() << "Button is clicked!";
}
