#include "../Header/Signin.h"
Signin::Signin(QObject *parent) : QObject(parent) {}

void Signin::verifyPasswordUsername(const QString &username, const QString &password, const QString &passwordCheck) {
    //implement the check of the username
    bool taken=false;
    if (taken){
        emit openUsernameError();
    }
    else{
        if (password == passwordCheck) {
            emit openMarketPage(); // Open Fridge.qml
        } else {
            emit openPasswordError(); // Show error
        }
    }
}
