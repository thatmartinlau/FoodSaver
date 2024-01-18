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





vector<string> serialize(vector<vector<string>> vector_of_vector){
    vector<string> just_vector;
    for(int i =0 ; i<sizeof(vector_of_vector); i++){
        for(int j =0; j<sizeof(vector_of_vector[i]); j++ ){
            just_vector.push_back(vector_of_vector[i][j]);
        }

    }
    return just_vector;

}

vector<string> serialize_offer_list(vector<vector<vector<string>>> vector_of_vector_of_vector){
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


// deserialize --> vector<string> --> vector<vector<string>>

// [Ingredient1, Ingredient2, .... , [Price]]

//Ingredient_i = [name, expiry_date, quantity, category, priority_level]
vector<vector<string>> deserialize_offer (vector<string> offer){
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


vector<vector<string>> deserialize_fridge(vector<string> fridge){
    vector<vector<string>> fridge_deser;

    for(int i =0; i<sizeof(fridge); i+=6){

        vector<string> inter_vector;
        for(int j =i; j<i+6; j++){
            inter_vector.push_back(fridge[j]);

        }
        fridge_deser.push_back(inter_vector);

    }


    return fridge_deser;



}

vector<vector<vector<string>>> deserialize_offer_list (vector<string> offer_list){
    vector<vector<vector<string>>> offer_deser;
    for(int i = 0 ; i<offer_list.size();i++){
        vector<string> inter_vector;
        inter_vector.push_back(offer_list[i]);
        offer_deser.push_back(deserialize_offer(inter_vector));

    }



    return offer_deser;

}


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
    basic_user_data() {}
};


#endif
