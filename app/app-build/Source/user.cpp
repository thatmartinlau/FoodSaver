#include "../Header/user.h"

//#include <iostream>
//#include <list>
//#include <ctime>
//#include <chrono>
//using namespace std;

//USER
User::User(std::string username, std::string password, std::string telegram_username) {
    this->username = username;
    this->password = password;
    this->telegram_username = telegram_username;
}

User::~User() {
}

void User::set_username(std::string username) {
    this->username = username;
}

std::string User::get_username() {
    return username;
}

bool User::check_password(std::string input_username, std::string input_password) {
    return true;
}

void User::set_telegram(std::string telegram) {
    telegram_username = telegram;
}

std::string User::get_telegram() {
    return telegram_username;
}

std::string User::get_gender() {
    return gender;
}

std::string User::get_display_name() {
    return display_name;
}
std::string User::get_room_number() {
    return room_number;
}

std::string User::get_promotion() {
    return promotion;
}

std::string User::get_phone_number() {
    return phone_number;
}

bool User::is_username(std::string username) {
    //implement logic for checking if a username has already been used
    return false;
}

bool User::register_user() {
    //implement logic for registering the user in the server
    return true;
}
bool User::register_new_user() {
    //implement logic for registering the user in the server
    return true;
}

void User::set_gender(std::string gender){
    this->gender=gender;
}
void User::set_phone_number(std::string phone_number){
   this->phone_number=phone_number;
}
void User::set_room_number(std::string room_number){
    this->room_number=room_number;
}
void User::set_promotion(std::string promotion){
    this->promotion=promotion;
}
void User::set_display_name(std::string display_name){
    this->display_name=display_name;
}

void User::set_password(std::string password){
    this->password=password;
}

void User::set_food_and_dietary_restrictions(std::list<bool> r){
    this->food_and_dietary_restrictions=r;
}

std::list<bool> User::get_food_and_dietary_restrictions(){
    return food_and_dietary_restrictions;
}
