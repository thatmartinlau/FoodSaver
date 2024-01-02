#ifndef SIGNIN_H
#define SIGNIN_H

#include <QObject>
#include <QString>

class Signin : public QObject {
    Q_OBJECT

public:
    explicit Signin(QObject *parent = nullptr);

    Q_INVOKABLE void verifyPassword(const QString &username, const QString &password);

signals:
    void openPasswordError();
    void openMarketPage();
};

#endif // SIGNIN_H
