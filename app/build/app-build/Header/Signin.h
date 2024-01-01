#ifndef SIGNIN_H
#define SIGNIN_H

#include <QObject>
#include <QString>
#include <QList>

// Forward declaration of the User class
class User;

class Signin : public QObject {
    Q_OBJECT

public:
    explicit Signin(QObject *parent = nullptr);
    ~Signin();

    Q_INVOKABLE void createUser(const QString &username, const QString &password, const QString &passwordCheck);

signals:
    void usernameTaken();
    void passwordMismatch();
    void userCreated();

private:
    QList<User*> users; // A list to store registered users
    bool isUsernameTaken(const QString &username);
};

#endif // SIGNIN_H
