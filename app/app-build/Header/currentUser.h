#ifndef CURRENTUSER_H
#define CURRENTUSER_H


#include "user.h"

class CurrentUser {
public:
    static User* currentUser;

    // Static member function to set the current user
    static void setCurrentUser(const std::string& username, const std::string& password) {
        if (currentUser == nullptr) {
            currentUser = new User(username, password);
        } else {
            // If a user already exists, update its attributes
            currentUser->set_username(username);
            currentUser->set_password(password);
            // Update other attributes as needed
        }
    }
};


#endif // CURRENTUSER_H

