#ifndef USER_H
#define USER_H

#include "fridge.h"
#include "offer.h"

//#include <iostream>
#include <list>
//#include <string>
//#include <ctime>
//#include "nlohmann/json.hpp"
//using json = nlohmann::json;
//using namespace std;

class User{
public:
    User();
    User(std::string username, std::string password);
    ~User();
    void set_username(std::string username);
    std::string get_username();
    bool check_password(std::string input_password);
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
    //json toJson () const;
    void add_offer(Offer new_offer);
    Offer remove_offer(Offer *offer_to_delete);
    std::vector<Offer> get_my_offers();

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
    
};

#endif // USER_H
