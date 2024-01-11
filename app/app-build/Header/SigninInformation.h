#ifndef SIGNININFORMATION_H
#define SIGNININFORMATION_H
#include <QObject>

class SigninInfo : public QObject {
    Q_OBJECT
public:
    explicit SigninInfo(QObject *parent = nullptr);

    Q_INVOKABLE bool signInInfo();

signals:
    void openMarketPage();
};
#endif // SIGNININFORMATION_H
