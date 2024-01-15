#include "../Header/Signin.h"
#include "../Header/user.h"
#include "../Header/currentUser.h"


Signin::Signin(QObject *parent) : QObject(parent) {}

bool Signin::signIn(const QString &username, const QString &password, const QString &passwordCheck, const QString &telegram) {
    if (username== "") {
        emit openNoUsernameError();
        return false;
    }

    else if (User::is_username(username.toStdString())) {
        emit openUsernameError();
        return false;
    }

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
        emit openNextPage();
        CurrentUser::currentUser.User::set_username(username.toStdString());
        CurrentUser::currentUser.User::set_password(password.toStdString());
        CurrentUser::currentUser.register_user();
        CurrentUser::currentUser.register_new_user();
        return true;
    }
}

