#include "../Header/Signin.h"
Signin::Signin(QObject *parent) : QObject(parent) {}


bool Signin::signIn(const QString &username, const QString &password, const QString &password_check) {
    //STILL NEED TO ADD IN THE VERIFICATION FOR EXISTING USERNAME
    if (username== "") {
        emit openNoUsernameError();
        return false;
    }
    else if (username!= "Fanny") {
        emit openUsernameError(); //show username error
        return false;
    }
    else if (password ==""||password_check=="") {
        emit openNoPasswordError(); //show password error
        return false;
    }
    else if (password != password_check) {
        emit openPasswordError(); //show password error
        return false;
    }
    else {
        emit openMarketPage(); //open Market.qml
        return true;
    }
}
