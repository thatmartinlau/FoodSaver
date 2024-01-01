#include "../Header/Signin.h"
#include "../Header/user.h"

Signin::Signin(QObject *parent) : QObject(parent) {}

Signin::~Signin() {}

void Signin::createUser(const QString &username, const QString &password, const QString &passwordCheck) {
    if (isUsernameTaken(username)) {
        emit usernameTaken();
    } else if (password != passwordCheck) {
        emit passwordMismatch();
    } else {
        // Create a new user
        User *newUser = new User(username.toStdString(), password.toStdString());
        // Need to implement adding user to a list of users
        users.append(newUser);
        emit userCreated();
    }
}

bool Signin::isUsernameTaken(const QString &username) {
    // Iterate through existing users to check if the username is already taken
    for (User* user : users) {
        if (user->get_username() == username.toStdString()) {
            return true; // Username is already taken
        }
    }
    return false; // Username is available
}
