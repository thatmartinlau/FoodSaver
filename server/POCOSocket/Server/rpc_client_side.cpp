#include "rpc/client.h"
#include <string>
#include "rpc_client_side.hpp"

std::string HOST_SERVER_NAME = "127.0.0.1"; //change to Xiaxi's thing later
int HOST_SERVER_PORT = 3333;

ServerUser::ServerUser(std::string username, std::string psswd) {
    int id = 0; //for now, thenn code hash or wtv
    login_info.push_back(id);
    login_info.push_back(username);
    login_info.push_back(psswd);    
    client(HOST_SERVER_NAME, HOST_SERVER_PORT);
    std::cout << create_user();
}

ServerUser::~ServerUser() {}

bool ServerUser::create_user() { //independent of whether user exists already: if he exists already, simply return true in add_user.
    bool created = client.call("add_user", username, password).as<bool>();
    return created == true ? true : false;
}


void ServerUser::remove_self() {
    client.call("remove_user", login_info, username, password);
}


//OSCAR's CODE ADAPTED BY ADAM:
std::vector toVector(Ingredient &ingr) { //returns vector as [name, quantity, category, expiry_date, priority_level]
    std::vector vec;
    vec.push_back(*ingr.name);
    vec.push_back(*ingr.quantity);
    vec.push_back(*ingr.category);
    vec.push_back(*ingr.expiry_date);
    vec.push_back(*ingr.priority_level);
    return vec
}

void ServerUser::update_fridge(Fridge f_input) {
    //convert to database-wanted format: OSCAR'S METHOD
    std::vector fridge;
    for (std::list<Ingredient>::iterator i = f_input.ingredient_list->begin(); i != f_input.ingredient_list->end(); i++) {
        
        //convert ingredient to vector format USING OSCAR's CODE
        std::vector ingredient;
        fridge.push_back(toVector(ingredient));
    }
    //send as new format
    client.call("update_fridge", fridge);
}





