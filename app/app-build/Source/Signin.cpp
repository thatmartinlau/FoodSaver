#include "../Header/Signin.h"
#include "../Header/user.h"
#include <string>
#include <iostream>

Signin::Signin(QObject *parent) : QObject(parent) {}

//Add telegram
bool Signin::signIn(const QString &username, const QString &password, const QString &password_check, const QString &telegram) {

    emit openMarketPage();
    return true;
}
