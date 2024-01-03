#ifndef LOGIN_H
#define LOGIN_H

#include <QObject>
#include <QString>

class Login: public QObject {
    Q_OBJECT

public:
    explicit Login(QObject *parent = nullptr);

    Q_INVOKABLE void logIn(const QString &username, const QString &password);

signals:
    void openMarketPage();
    void openFridgePage();
    //void openPasswordError();
    //void openUsernameError();
};

#endif // LOGIN_H
