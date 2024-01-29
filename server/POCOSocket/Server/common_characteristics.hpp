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
    for(int i =0 ; i<vector_of_vector.size(); i++){
        for(int j =0; j<vector_of_vector[i].size(); j++ ){
            just_vector.push_back(vector_of_vector[i][j]);
        }
    }
    return just_vector;
}

inline vector<string> serialize_offer_list(vector<vector<vector<string>>> vector_of_vector_of_vector){
    vector<string> just_vector;
    for(int i =0 ; i<vector_of_vector_of_vector.size(); i++){
        for (int k = 0; k < 5; k++) {
            just_vector.push_back(vector_of_vector_of_vector[i][0][k]);
        }
        just_vector.push_back(vector_of_vector_of_vector[i][1][0]);
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
    for(int i =0; i<offer_list.size(); i+=6){
        vector<string> vector_inter;
        for(int j = i ; j<i+6; j++){
            vector_inter.push_back(offer_list[j]); // --> vector of an offer ;
        }

        vector<vector<string>> offer = deserialize_offer(vector_inter);

        deserialize_offer_list.push_back(offer);

    }

    return deserialize_offer_list;
}


inline vector<vector<string>> deserialize_fridge(vector<string> fridge){
    vector<vector<string>> fridge_deser;

    for(int i =0; i<fridge.size(); i+=5){

        vector<string> inter_vector;
        for(int j =i; j<i+5; j++){
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


inline vector<string> serialize_unMap(unordered_map<string, vector<vector<vector<string>>>> map){
    vector<string> serialized_map;
    for (auto it=map.begin(); it!= map.end(); it++) {
        serialized_map.push_back(it->first);
        vector<string> offer_list_as_str = serialize_offer_list(it->second);
        serialized_map.insert(serialized_map.end(), offer_list_as_str.begin(), offer_list_as_str.end());
        string comma_sep = ",";
        serialized_map.push_back(comma_sep); //separator between users, used in deserialized functions.
    }
    serialized_map.erase(serialized_map.end()-1);//get rid of extra comma.
    return serialized_map;
}

inline unordered_map<string, vector<vector<vector<string>>>> deserialize_map(vector<string> map){
    unordered_map<string, vector<vector<vector<string>>>> resultant_map;
    int count = 0;
    for (int i=0; i < map.size(); i++) {
        string comma_sep = ",";        
        if (map[i] == comma_sep) {
            vector<string> serialized_offer_list;
            string u_name = map[count];
            for (int j = count + 1; j < i; j++) {
                serialized_offer_list.push_back(map[j]);
            }
            resultant_map[u_name] = deserialize_offer_list(serialized_offer_list);
            count = i+1;
        }
        
        
    }
    
    return resultant_map;
}


#endif
