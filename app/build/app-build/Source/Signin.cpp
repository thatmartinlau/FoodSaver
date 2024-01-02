#include "../Header/Signin.h"

Signin::Signin(QObject *parent) : QObject(parent) {}

void Signin::signIn(const QString &username, const QString &password) {
    if (username != "Fanny" || password != "Fanny") {
        emit openFridgePage(); // Open Fridge.qml
    } else {
        emit openMarketPage(); // Open Market.qml
    }
}
