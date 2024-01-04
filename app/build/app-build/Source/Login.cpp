#include "../Header/Login.h"

Login::Login(QObject *parent) : QObject(parent) {}

void Login::logIn(const QString &username, const QString &password) {
    if (username == "user" && password == "pass") {
        emit openMarketPage();
    } else {
        emit showUsernameError();
        emit showPasswordError();
    }
}
