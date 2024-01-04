#ifndef LOGIN_H
#define LOGIN_H

#include <QObject>
#include <QString>

class Login : public QObject {
    Q_OBJECT

public:
    explicit Login(QObject *parent = nullptr);

public slots:
    void logIn(const QString &username, const QString &password);

signals:
    void openMarketPage();
    void showUsernameError();
    void showPasswordError();
};

#endif // LOGIN_H
