#ifndef COMMON_CHARACTERISTICS
#define COMMON_CHARACTERISTICS
//all includes COMMON to both server_side.cpp and rpc_client_side.hpp
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

//ALl constant names, common to both, for comms.




//all struct types common to both:
//struct triple_vector {
//    vector<vector<vector<string>>> triple_vect;
//    MSGPACK_DEFINE_ARRAY(triple_vect);
//    //struct constructor:
//    triple_vector(vector<vector<vector<string>>> triple_vec_of_strings) {triple_vect = triple_vec_of_strings;}
//    triple_vector() {}
//};

//struct double_vector {
//    vector<vector<string>> double_vect;
//    MSGPACK_DEFINE_ARRAY(double_vect);
//    double_vector(vector<vector<string>> double_vec_of_strings) {double_vect = double_vec_of_strings;}
//    double_vector() {}
//};

//struct ingredient_struct{
//    string name, quantity, expiry_date, category, priority_level;
//    MSGPACK_DEFINE_ARRAY(name, quantity, expiry_date, category, priority_level);
//    ingredient_struct(vector<string> ingredient) {
//        name = ingredient[0];
//        quantity = ingredient[1];
//        expiry_date = ingredient[2];
//        category = ingredient[3];
//        priority_level = ingredient[4];        
//    }
//    ingredient_struct() {}
//};

struct basic_user_data {
    string display_name;
    string telegram_username;
    int gender;
    int promotion;
    string building_address;
    int phone_number;
    list<bool> food_and_dietary_restrictions;
    int telegram_notifications;
    int marketplace_notifications;
//    MSGPACK_DEFINE_ARRAY(display_name, telegram_username, gender, promotion, building_address, phone_number, food_and_dietary_restrictions, telegram_notifications, marketplace_notifications);
    basic_user_data() {}
};



//USING method:
//using vector_of_ingredients = vector<ingredient_struct>;
//using vector_of_offers = vector<offer_struct>;

//

#endif
