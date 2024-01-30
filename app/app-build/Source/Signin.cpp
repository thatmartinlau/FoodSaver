#include "../Header/Signin.h"
#include "../Header/user.h"
#include "../Header/currentUser.h"


Signin::Signin(QObject *parent) : QObject(parent) {}

bool Signin::signIn(const QString &username, const QString &password, const QString &passwordCheck) {
    // check that a username has been given
    if (username== "") {
        emit openNoUsernameError();
        return false;
    }
    // check that the username is not taken
    else if (User::is_username(username.toStdString())) {
        emit openUsernameError();
        return false;
    }
    // check that password and password check have been filled out
    else if (password== "" || passwordCheck== "") {
        emit openNoPasswordError();
        return false;
    }
    // Minimum 8 characters in password
    else if (password.length() <8) {
        emit openShortPasswordError();
        return false;
    }
    // check that the password and password check match
    else if (password != passwordCheck) {
        emit openPasswordError();
        return false;
    }

    // If all conditions are satisfied: initialize user
    else{
        emit openNextPage();
        CurrentUser::currentUser.User::set_username(username.toStdString());
        CurrentUser::currentUser.User::set_password(password.toStdString());
        CurrentUser::currentUser.register_user();
        CurrentUser::currentUser.register_new_user();
        return true;
    }
}

