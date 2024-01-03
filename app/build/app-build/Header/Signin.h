#ifndef SIGNIN_H
#define SIGNIN_H

#include <QObject>
#include <QString>

class Signin : public QObject {
    Q_OBJECT

public:
    explicit Signin(QObject *parent = nullptr);

    Q_INVOKABLE void verifyPasswordUsername(const QString &username, const QString &password, const QString &passwordCheck);

signals:
    void openPasswordError();
    void openUsernameError();
    void openMarketPage();
};

#endif // SIGNIN_H
