#include "mainwindow.h"
#include "temporary.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    temporary t;

    w.show();
    return a.exec();
}
