#include "../Header/Signin.h"
#include "../Header/user.h"
Signin::Signin(QObject *parent) : QObject(parent) {}

//Add telegram
bool Signin::signIn(const QString &username, const QString &password, const QString &password_check, const QString &telegram) {
    //STILL NEED TO ADD IN THE VERIFICATION FOR EXISTING USERNAME
    if (username== "") {
        emit openNoUsernameError();
        return false;
    }
    else if {
        emit openUsernameError(); //show username error
        User new_user;
        new_user.set_username(username);
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
        User new_user(username, password, telegram);
        emit openMarketPage(); //open Market.qml
        return true;
    }
}
