#pragma once
#ifndef USER_H
#define USER_H

#include "fridge.h"
#include "offer.h"
#include "recipe.h"
#include "rpc_client_side.hpp"

//#include <iostream>
#include <list>
//#include <string>
//#include <ctime>
//#include "nlohmann/json.hpp"
//using json = nlohmann::json;
//using namespace std;

//#include "client_side_connection/server_to_backend_connection/rpc_client_side.hpp"
//include "" esma's thing

//fix circular include loop:
class ServerUser;

class User{
public:
    User();
    User(std::string username, std::string password);
    ~User();
    void set_username(std::string username);
    std::string get_username();
    bool check_password(std::string input_username, std::string input_password);
    bool is_username(std::string username);
    void set_distplay_name(std::string display_name);
    std::string get_display_name();
    void set_telegram_username(std::string telegram);
    std::string get_telegram_username();
    void set_gender(int gender);
    int get_gender();
    void set_promotion(int promotion);
    int get_promotion();
    void set_building_address(std::string building_address);
    std::string get_building_address();
    void set_phone_number(int phone_number);
    int get_phone_number();
    void set_food_and_dietary_restrictions(std::list<bool> r);
    std::list<bool> get_food_and_dietary_restrictions();
    void set_telegram_notifications(int t);
    int get_telegram_notifications();
    void set_marketplace_notifications(int m);
    int get_marketplace_notifications();
    std::vector<Offer> get_my_offers();
    void add_offer(Offer new_offer);
    Fridge get_user_fridge();
    void add_ingredient_fridge(Ingredient elt);
    Offer remove_offer(Offer *offer_to_delete);
    void like_recipe(Recipe recipe);
    void unlike_recipe(Recipe recipe);
    bool operator==(User& other);

    void update_user_characteritics(std::string display_name1, std::string telegram_username1,  int gender1 ,int promotion1,  std::string building_address1, int phone_number1,    std::list<bool> food_and_dietary_restrictions1, int telegram_notifications1, int marketplace_notifications1, Fridge user_fridge1, std::vector<Offer> offer_list1){
        display_name = display_name1;
        telegram_username = telegram_username1;
        gender = gender1;
        promotion = promotion1;
        building_address = building_address1;
        phone_number = phone_number1;
        food_and_dietary_restrictions = food_and_dietary_restrictions1;
        telegram_notifications = telegram_notifications1;
        marketplace_notifications = marketplace_notifications1;
        user_fridge1 = user_fridge ;
        offer_list1 = offer_list;
    }
private:
    std::string username;
    std::string password;
    std::string display_name;
    std::string telegram_username;
    int gender;
    int promotion;
    std::string building_address;
    int phone_number;
    std::list<bool> food_and_dietary_restrictions;
    int telegram_notifications;
    int marketplace_notifications;
    Fridge user_fridge;
    std::vector<Offer> offer_list;
    std::vector<Recipe> liked_recipes;
    ServerUser *server_user;
};


std::vector<std::string> getUsers();

#endif // USER_H
