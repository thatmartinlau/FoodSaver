#include "../Header/Login.h"
#include "../Header/user.h"
#include "../Header/currentUser.h"
#include <string>
#include <iostream>


Login::Login(QObject *parent) : QObject(parent) {}

bool Login::logIn(const QString &username, const QString &password) {
    // check that a username has been given
     if (username== "") {
         emit openNoUsernameError2();
         return false;
     }
    // check that the password has been given
     else if (password== "") {
         emit openNoPasswordError2();
         return false;
     }
     // check that the username exists
     else if (!User::is_username(username.toStdString())) {
         emit openUsernameError2();
         return false;
     }
     // check that the password is correct
     else if (!User::check_password(username.toStdString(),password.toStdString())) {
         emit openPasswordError2();
         return false;
     }

     // If all conditions are satisfied: Initilize user information
     else{
         emit openMarketPage2();
         CurrentUser::currentUser.User::set_username(username.toStdString());
         CurrentUser::currentUser.User::set_password(password.toStdString());
         CurrentUser::currentUser.register_user();
         return true;
     }
}

