#include "user.h"

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
    return input_username == username && input_password == password;
}

// Returns true if username in user and false otherwise
bool User::is_username(string username) {
    vector<string> list_usernames = get_user_name_list();
    for (int i = 0; i < len(list_usernames); i++) {
        if (list_usernames[i] == username) {
            return true;
        }
    }
    return false;
}

void User::set_distplay_name(std::string display_name) {
    this->display_name = display_name;
}

std::string User::get_display_name() {
    return display_name;
}

void User::set_telegram_username(std::string telegram) {
    telegram_username = telegram;
}

std::string User::get_telegram_username() {
    return telegram_username;
}


void User::set_gender(int gender) {
    this->gender = gender;
}

int User::get_gender() {
    return gender;
}

void User::set_promotion(int promotion) {
    this->promotion = promotion;
}

int User::get_promotion() {
    return promotion;
}

void User::set_building_address(std::string building_address) {
    this->building_address = building_address;
}

std::string User::get_building_address() {
    return building_address;
}

void User::set_phone_number(int phone_number) {
    this->phone_number = phone_number;
}

int User::get_phone_number() {
    return phone_number;
}

void User::set_food_and_dietary_restrictions(std::list<bool> r) {
    this->food_and_dietary_restrictions = r;
}

std::list<bool> User::get_food_and_dietary_restrictions() {
    return food_and_dietary_restrictions;
}

void User::set_telegram_notifications(int t) {
    this->telegram_notifications = t;
}

int User::get_telegram_notifications() {
    return telegram_notifications;
}

void User::set_marketplace_notifications(int m) {
    this->marketplace_notifications = m;
}

int User::get_marketplace_notifications() {
    return marketplace_notifications;
}

void User::add_offer(Offer new_offer) {
    offer_list.push_back(new_offer);
}

Offer User::remove_offer(Offer *offer_to_delete) {
    // Check if offer_to_delete is nullptr
    if (offer_to_delete == nullptr) {
        throw std::invalid_argument("Null pointer passed to remove_offer");
    }

    for (auto it = offer_list.begin(); it != offer_list.end(); ++it) {
        if (*it == *offer_to_delete) {
            Offer foundOffer = *it;
            offer_list.erase(it);
            return foundOffer;
        }
    }

    throw std::runtime_error("Ingredient not found in the fridge");
}

std::vector<Offer> User::get_my_offers(){
    return offer_list;
}
