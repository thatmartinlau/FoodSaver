#include "../Header/Login.h"

Login::Login(QObject *parent) : QObject(parent) {}

void Login::verifyPasswordUsername(const QString &username, const QString &password) {
    //implement logic to verify password
    bool validUsername=true;
    bool correctPassword=true;
    if (validUsername && correctPassword) {
        emit openMarketPage(); // Open Fridge.qml
    } else {
        emit openPasswordUsernameError(); // Show error
    }
}
