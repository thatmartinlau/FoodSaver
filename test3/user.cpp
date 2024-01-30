#include "user.h"

//#include <iostream>
//#include <list>
//#include <ctime>
//#include <chrono>
//using namespace std;

//USER
User::User() {}

User::User(std::string username, std::string password) {
    this->username = username;
    this->password = password;
    ServerUser srv_usr(username, password);
    server_user = &srv_usr;
    user_fridge = server_user->get_fridge();
    offer_list = server_user->get_offer_list();
    food_and_dietary_restrictions = server_user->get_food_restrictions();
    basic_user_data basic_u_data;
    basic_u_data = server_user->get_basic_user_data();
    //Oscar, coded constructor directly in here, without added function . Initializer list style.
    display_name = basic_u_data.display_name;
    telegram_username = basic_u_data.telegram_username;
    gender = basic_u_data.gender;
    promotion = basic_u_data.promotion;
    building_address = basic_u_data.building_address;
    phone_number = basic_u_data.phone_number;
    telegram_notifications = basic_u_data.telegram_notifications;
    marketplace_notifications = basic_u_data.marketplace_notifications;
}



User::~User() {
}

void User::set_username(std::string username) {
    this->username = username;
    server_user->update_user_name_and_password(username, password);
}

void User::set_password(std::string password) {
    this->password = password;
    server_user->update_user_name_and_password(username, password);
}

std::string User::get_username() {
    return username;
}

bool User::check_password(std::string input_username, std::string input_password) {
    return input_username == username && input_password == password;
}


Fridge User::get_user_fridge(){
    return this->user_fridge;
    }

void User::add_ingredient_fridge(Ingredient elt){
    user_fridge.add_elt(elt);
    server_user->update_fridge(user_fridge);
}

/*testing purpose*/
bool User::is_username(std::string username) {
    return true;
}

/*
// Returns true if username in user and false otherwise
bool User::is_username(std::string username) {
    std::vector<std::string> list_usernames = get_user_name_list();
    for (int i = 0; i < len(list_usernames); i++) {
        if (list_usernames[i] == username) {
            return true;
        }
    }
    return false;
}
*/

// If the server crashes
// Returns true if username in user and false otherwise
/*
bool User::is_username(std::string username) {
    std::vector<User> list_usernames = BackupServer::get_user_list();
    for (int i = 0; i < list_usernames.size(); i++) {
        if (list_usernames[i].get_username() == username) {
            return true;
        }
    }
    return false;
}
*/

void User::set_display_name(std::string display_name) {
    this->display_name = display_name;
    server_user->update_user_characteristics(this);
}

std::string User::get_display_name() {
    return display_name;
}

void User::set_telegram_username(std::string telegram) {
    telegram_username = telegram;
    server_user->update_user_characteristics(this);    
}

void User::set_room_number(std::string room) {
    building_address = room;
    server_user->update_user_characteristics(this);
}

std::string User::get_room_number() {
    return building_address;
}

std::string User::get_telegram_username() {
    return telegram_username;
}


void User::set_gender(int gender) {
    this->gender = gender;
    server_user->update_user_characteristics(this);    
}

int User::get_gender() {
    return gender;
}

void User::set_promotion(int promotion) {
    this->promotion = promotion;
    server_user->update_user_characteristics(this);
}

int User::get_promotion() {
    return promotion;
}

void User::set_building_address(std::string building_address) {
    this->building_address = building_address;
    server_user->update_user_characteristics(this);    
}

std::string User::get_building_address() {
    return building_address;
}

void User::set_phone_number(int phone_number) {
    this->phone_number = phone_number;
    server_user->update_user_characteristics(this);        
}

int User::get_phone_number() {
    return phone_number;
}

void User::set_food_and_dietary_restrictions(std::list<bool> r) {
    this->food_and_dietary_restrictions = r;
    server_user->update_user_characteristics(this);        
}

std::list<bool> User::get_food_and_dietary_restrictions() {
    return food_and_dietary_restrictions;
}

void User::set_telegram_notifications(int t) {
    this->telegram_notifications = t;
    server_user->update_user_characteristics(this);            
}

int User::get_telegram_notifications() {
    return telegram_notifications;
}

void User::set_marketplace_notifications(int m) {
    this->marketplace_notifications = m;
    server_user->update_user_characteristics(this);        
    
}

int User::get_marketplace_notifications() {
    return marketplace_notifications;
}

void User::add_offer(Offer new_offer) {
    offer_list.push_back(new_offer);
    server_user->update_offer_list(offer_list);
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
            //sorry Sixtine, looks ugly, but best place to put it:
            server_user->update_offer_list(offer_list);
            return foundOffer;
        }
    }

    throw std::runtime_error("Offer not found in the offers");
}

std::vector<Offer> User::get_my_offers(){
    return offer_list;
}

/*
std::vector<std::string> get_all_clients() {
    rpc::clients cl(HOST_SERVER_NAME, HOST_SERVER_PORT);

    auto clients = cl.call("getUsers").as<
        std::vector<std::string> > ();

    return clients;
}
*/
void User::like_recipe(Recipe recipe) {
    liked_recipes.push_back(recipe);
}

void User::unlike_recipe(Recipe recipe) {
    for (auto it = liked_recipes.begin(); it != liked_recipes.end(); ++it) {
        if (*it == recipe) {
            liked_recipes.erase(it);
        }
    }

    throw std::runtime_error("Ingredient not found in the fridge");
}

bool User::operator==(User& other) {
    return (this->get_username() == other.get_username());
}

bool User::register_user() {
    //implement logic for registering the user in the server
    return true;
}
bool User::register_new_user() {
    //implement logic for registering the user in the server
    return true;
}


/*
void User::set_user_params_from_db() {
    
}

*/


