#ifndef COMMON_CHARACTERISTICS
#define COMMON_CHARACTERISTICS
//all includes COMMON to both server_side.cpp and rpc_client_side.hpp
#include <unordered_map>
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

//strucut in common between server_side.cpp and webteste/client_side.cpp
struct basic_user_data {
    string display_name;
    string telegram_username;
    string building_address;
    int gender;
    int promotion;
    int phone_number;
    int telegram_notifications;
    list<bool> food_and_dietary_restrictions;
    int marketplace_notifications;
    basic_user_data() {}
};


inline vector<string> serialize_basic_data_of_user(basic_user_data u_data) {
    vector<string> serialized_basic_data;
    serialized_basic_data.push_back(u_data.display_name);
    serialized_basic_data.push_back(u_data.telegram_username);
    serialized_basic_data.push_back(u_data.building_address);
    serialized_basic_data.push_back(to_string(u_data.gender));    
    serialized_basic_data.push_back(to_string(u_data.promotion));
    serialized_basic_data.push_back(to_string(u_data.telegram_notifications));
    serialized_basic_data.push_back(to_string(u_data.marketplace_notifications));
    return serialized_basic_data;
}

inline basic_user_data deserialize_basic_data_of_user(vector<string> user_data_as_str_vec) {
    basic_user_data basic_u_data;
    basic_u_data.marketplace_notifications = stoi(user_data_as_str_vec[0]);
    basic_u_data.telegram_notifications= stoi(user_data_as_str_vec[1]);
    basic_u_data.promotion = stoi(user_data_as_str_vec[2]);
    basic_u_data.gender = stoi(user_data_as_str_vec[3]);
    basic_u_data.building_address = user_data_as_str_vec[4];
    basic_u_data.telegram_username = user_data_as_str_vec[5];
    basic_u_data.display_name = user_data_as_str_vec[6];
}


//Going to copy paste the deserialize and serialize functions !

// do the recipe thing

// serialize --> vector<vector<string> to vector<string>

inline vector<string> serialize(vector<vector<string>> vector_of_vector){
    vector<string> just_vector;
    for(int i =0 ; i<sizeof(vector_of_vector); i++){
        for(int j =0; j<sizeof(vector_of_vector[i]); j++ ){
            just_vector.push_back(vector_of_vector[i][j]);
        }
    }
    return just_vector;
}

inline vector<string> serialize_offer_list(vector<vector<vector<string>>> vector_of_vector_of_vector){
    vector<string> just_vector;
    for(int i =0 ; i<sizeof(vector_of_vector_of_vector); i++){
        for(int j =0; j<sizeof(vector_of_vector_of_vector[i]); j++ ){

             for(int k =0; k<sizeof(vector_of_vector_of_vector[j]); k++ ){

                just_vector.push_back(vector_of_vector_of_vector[i][j][k]);
            }
        }
    }
    return just_vector;

}


inline vector<string> serialize_triple (vector<vector<vector<string>>> vector_triple){
    vector<string> just_vector;

    for(int i =0 ; i<vector_triple.size(); i++){
        for(int j =0 ; j<vector_triple[i].size(); j++){
            for (int k=0; k<vector_triple[i][j].size(); k++){
                just_vector.push_back(vector_triple[i][j][k]);

            }

        }

    }
    return just_vector;
}


inline vector<string> serialize_unMap(unordered_map<string, vector<vector<vector<string>>>> maps){
    vector<string> just_vector;
     auto it = maps.begin();
     just_vector.push_back(it->first);
     vector<vector<vector<string>>> offer_lists;
     vector<string> dec_ol = serialize_offer_list(it->second);

     for(int k =0; k<sizeof(dec_ol); k++ ){
        just_vector.push_back(dec_ol[k]);
     }

     return just_vector;

}





// deserialize --> vector<string> --> vector<vector<string>>

// [Ingredient1, Ingredient2, .... , [Price]

//Ingredient_i = [name, expiry_date, quantity, category, priority_level]
inline vector<vector<string>> deserialize_offer (vector<string> offer){
    vector<vector<string>> offer_deser;
    for(int i = 0 ; i<sizeof(offer)-1;i+=6){
        vector<string> inter_vector;
        for(int j=i; j<i+6; j++){
            inter_vector.push_back(offer[j]);
        }
        offer_deser.push_back(inter_vector);
    }

    string price = offer.back();

    vector<string> vector_price;
    vector_price.push_back(price);
    offer_deser.push_back(vector_price);

    return offer_deser;

}


inline vector<vector<vector<string>>> deserialize_offer_list(vector<string> offer_list){

    vector<vector<vector<string>>> deserialize_offer_list;
    for(int i =0; i<offer_list.size(); i+=7){
        vector<string> vector_inter;
        for(int j = i ; j<i+7; j++){
            vector_inter.push_back(offer_list[j]); // --> vector of an offer ;
        }

        vector<vector<string>> offer = deserialize_offer(vector_inter);

        deserialize_offer_list.push_back(offer);

    }

    return deserialize_offer_list;
}


inline vector<vector<string>> deserialize_fridge(vector<string> fridge){
    vector<vector<string>> fridge_deser;

    for(int i =0; i<fridge.size(); i+=6){

        vector<string> inter_vector;
        for(int j =i; j<i+6; j++){
            inter_vector.push_back(fridge[j]);

        }
        fridge_deser.push_back(inter_vector);

    }


    return fridge_deser;



}

inline vector<vector<vector<string>>> deserialize_offer_list2 (vector<string> offer_list){
    vector<vector<vector<string>>> offer_deser;
    for(int i = 0 ; i<offer_list.size();i++){
        vector<string> inter_vector;
        inter_vector.push_back(offer_list[i]);
        offer_deser.push_back(deserialize_offer(inter_vector));
    }
    return offer_deser;
}

inline unordered_map<string, vector<vector<vector<string>>>> deserialize_map(vector<string> mapInStr){
    unordered_map<string, vector<vector<vector<string>>>> result;
    for (const std::string& str : mapInStr) {
        std::istringstream iss(str);
        std::string key;
        iss >> key;


        std::string valueStr;
        iss >> std::ws;
        std::getline(iss, valueStr);

        // Deserialize the value string into the map value type
        std::vector<std::vector<std::vector<std::string>>> value = deserialize_offer_list({valueStr});

        // Insert into the map
        result[key] = value;
    }

    return result;
}



#endif
