#ifndef SIGNIN_H
#define SIGNIN_H

#include <QObject>
#include <QString>

class Signin : public QObject {
    Q_OBJECT

public:
    explicit Signin(QObject *parent = nullptr);

    Q_INVOKABLE bool signIn(const QString &username, const QString &password, const QString &password_check);

signals:
    void openMarketPage();
    void openPasswordError();
    void openUsernameError();
};

#endif // SIGNIN_H
