#ifndef LOGIN_H
#define LOGIN_H

#include <QObject>
#include <QString>


class Login : public QObject {
    Q_OBJECT

public:
    explicit Login(QObject *parent = nullptr);

    Q_INVOKABLE bool logIn(const QString &username, const QString &password);

public slots:
    void openNoUsernameError2();
    void openPasswordError2();
    void openUsernameError2();
    void openNoPasswordError2();
    void openMarketPage2();
};

#endif // LOGIN_H
