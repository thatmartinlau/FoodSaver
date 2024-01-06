#include "../Header/Login.h"

Login::Login(QObject *parent) : QObject(parent) {}

bool Login::checkCredentials(const QString &username, const QString &password) {
    return username == "user" && password == "pass";
}
