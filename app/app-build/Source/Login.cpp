#include "../Header/Login.h"
#include "../Header/user.h"
#include "../Header/currentUser.h"
#include <string>
#include <iostream>


Login::Login(QObject *parent) : QObject(parent) {}

 bool Login::logIn(const QString &username, const QString &password) {
     if (username== "") {
         emit openNoUsernameError2();
         return false;
     }


     else if (!User::is_username(username.toStdString())) {
         emit openUsernameError2();
         return false;
     }

     else if (password== "") {
         emit openNoPasswordError2();
         return false;
     }

     else if (!User::check_password(username.toStdString(),password.toStdString())) {
         emit openPasswordError2();
         return false;
     }

     // If all conditions are satisfied
     else{
         emit openMarketPage2();
         CurrentUser::currentUser.User::set_username(username.toStdString());
         CurrentUser::currentUser.User::set_password(password.toStdString());
         CurrentUser::currentUser.register_user();
         return true;
     }
}

