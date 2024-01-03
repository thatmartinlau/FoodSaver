#include "../Header/Login.h"
void Login::logIn(const QString &username, const QString &password) {
    if (username != "Fanny" || password != "Fanny") {
        emit openFridgePage(); // Open Fridge.qml
    } else {
        emit openMarketPage(); // Open Market.qml
    }
}
