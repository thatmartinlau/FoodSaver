#include "../Header/user.h"

//#include <iostream>
//#include <list>
//#include <ctime>
//#include <chrono>
//using namespace std;

//USER
User::User(std::string username, std::string password, std::string telegram) {
    this->username = username;
    this->password = password;
    this->telegram_username = telegram;
}

User::~User() {
}

std::string User::get_username() {
    return username;
}

bool User::check_password(std::string input_password) {
    return input_password == password;
}

void User::set_telegram(std::string telegram) {
    telegram_username = telegram;
}

std::string User::get_telegram() {
    return telegram_username;
}

bool is_username(std::string username) {
    //implement logic for checking if a username has already been used
    return true;
}
