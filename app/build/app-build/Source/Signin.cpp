#include "../Header/Signin.h"
Signin::Signin(QObject *parent) : QObject(parent) {}

void Signin::verifyPassword(const QString &password, const QString &passwordCheck) {
    if (password == passwordCheck) {
        emit openMarketPage(); // Open Fridge.qml
    } else {
        emit openPasswordError(); // Show error
    }
}
