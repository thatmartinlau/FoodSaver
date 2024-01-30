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

    basic_u_data.display_name = user_data_as_str_vec[0];

    basic_u_data.telegram_username = user_data_as_str_vec[1];

    basic_u_data.building_address = user_data_as_str_vec[2];

    basic_u_data.gender = stoi(user_data_as_str_vec[3]);

    basic_u_data.promotion = stoi(user_data_as_str_vec[4]);
    basic_u_data.phone_number= stoi(user_data_as_str_vec[5]);

    basic_u_data.telegram_notifications= stoi(user_data_as_str_vec[6]);

    basic_u_data.marketplace_notifications = stoi(user_data_as_str_vec[7]);

    return basic_u_data;

}


//Going to copy paste the deserialize and serialize functions !

// do the recipe thing

// serialize --> vector<vector<string> to vector<string>

inline vector<string> serialize(vector<vector<string>> vector_of_vector){
    vector<string> just_vector;
    for(size_t i = 0; i < vector_of_vector.size(); i++){
        for(size_t j = 0; j < vector_of_vector[i].size(); j++){
            just_vector.push_back(vector_of_vector[i][j]);
        }
    }
    return just_vector;
}

inline vector<string> serialize_offer_list(vector<vector<vector<string>>> vector_of_vector_of_vector){
    vector<string> just_vector;
    for(int i =0 ; i<vector_of_vector_of_vector.size(); i++){
        for(int j =0; j<vector_of_vector_of_vector[i].size(); j++ ){

             for(int k =0; k<vector_of_vector_of_vector[i][j].size(); k++ ){

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

inline vector<string> serialize_unMap(const unordered_map<string, vector<vector<vector<string>>>>& maps) {
    vector<string> serialized_map;

    for (const auto& pair : maps) {
        const string& username = pair.first;
        const auto& offers = pair.second;

        // Start with the username
        string user_offers = username + ": ";

        // Serialize each offer for this user
        vector<string> serialized_offers = serialize_offer_list(offers);
        for (const auto& offer : serialized_offers) {
            user_offers += offer + "; "; // Concatenate offers, separated by semicolons
        }

        // Add the complete string to the vector
        serialized_map.push_back(user_offers);
    }

    return serialized_map;
}




// deserialize --> vector<string> --> vector<vector<string>>

// [Ingredient1, Ingredient2, .... , [Price]

//Ingredient_i = [name, expiry_date, quantity, category, priority_level]
inline vector<vector<string>> deserialize_offer (vector<string> offer){
    vector<vector<string>> offer_deser;
    for(int i = 0 ; i<offer.size()-1;i+=6){
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

unordered_map<string, vector<vector<vector<string>>>> deserialize_map(const vector<string>& serialized_map) {
    unordered_map<string, vector<vector<vector<string>>>> maps;

    for (const auto& user_data : serialized_map) {
        size_t colon_pos = user_data.find(":");
        if (colon_pos == string::npos) continue; // Skip if format is incorrect

        string username = user_data.substr(0, colon_pos);
        string offers_str = user_data.substr(colon_pos + 2); // Skip ": " after username

        vector<vector<vector<string>>> user_offers;
        stringstream ss_offers(offers_str);
        string offer_str;

        while (getline(ss_offers, offer_str, ';')) {
            if (offer_str.empty() || offer_str[0] == ' ') {
                offer_str = offer_str.substr(1); // Remove leading space if present
            }

            stringstream ss_offer(offer_str);
            string element;
            vector<vector<string>> offer;

            while (getline(ss_offer, element, ' ')) {
                if (!element.empty()) {
                    // Assuming each element represents a part of the offer details
                    vector<string> offer_details;
                    offer_details.push_back(element); // Add each part to offer_details

                    // Assuming each offer detail is separated by a space
                    while (getline(ss_offer, element, ' ')) {
                        offer_details.push_back(element);
                    }

                    offer.push_back(offer_details);
                }
            }

            if (!offer.empty()) {
                user_offers.push_back(offer);
            }
        }

        if (!user_offers.empty()) {
            maps[username] = user_offers;
        }
    }

    return maps;
}


#endif
