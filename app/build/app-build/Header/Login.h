#ifndef LOGIN_H
#define LOGIN_H

#include <QObject>
#include <QString>

class Login : public QObject {
    Q_OBJECT

public:
    explicit Login(QObject *parent = nullptr);

    Q_INVOKABLE void verifyPasswordUsername(const QString &username, const QString &password);

signals:
    void openPasswordUsernameError();
    void openMarketPage();
};

#endif // LOGIN_H
