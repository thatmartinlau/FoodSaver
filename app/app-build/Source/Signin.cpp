
#include "../Header/Signin.h"
#include "../Header/user.h"

Signin::Signin(QObject *parent) : QObject(parent) {}

bool Signin::signIn(const QString &username, const QString &password, const QString &passwordCheck, const QString &telegram) {
    if (username== "") {
        emit openNoUsernameError();
        return false;
    }

    //THE FOLLOWING CODE DOES NOT WORK
    //else if (User::is_username(username.toStdString())) {
    //    emit openUsernameError();
    //    return false;
    //}

    else if (password== "" || passwordCheck== "") {
        emit openNoPasswordError();
        return false;
    }
    // Minimum 8 characters in password
    else if (password.length() <8) {
        emit openShortPasswordError();
        return false;
    }
    else if (password != passwordCheck) {
        emit openPasswordError();
        return false;
    }

    // If all conditions are satisfied
    else{
        emit openMarketPage();
        return true;
    }
}
