
#ifndef SIGNIN_H
#define SIGNIN_H

#include <QObject>

class Signin : public QObject {
    Q_OBJECT
public:
    explicit Signin(QObject *parent = nullptr);

    Q_INVOKABLE bool signIn(const QString &username, const QString &password, const QString &passwordCheck, const QString &telegram);

signals:
    void openNoUsernameError();
    void openPasswordError();
    void openUsernameError();
    void openNoPasswordError();
    void openMarketPage();
    void openShortPasswordError();
};

#endif // SIGNIN_H
