#include "rpc/client.h"
#include <string>
#include "rpc_client_side.hpp"

using namespace std;

string HOST_SERVER_NAME = "127.0.0.1"; //change to Server later.
int HOST_SERVER_PORT = 3333;

ServerUser::ServerUser(string usrname, string psswd) { //Add user to db if user not in db already. Oth, just initialise connection.
    username = usrname;
    password = psswd;
    client(HOST_SERVER_NAME, HOST_SERVER_PORT);
    client.call("add_user", username, password);
}

ServerUser::~ServerUser() {}


void ServerUser::delete_self_in_db() {
    client.call("remove_user", username, password);
}


void ServerUser::update_user(string new_username, string new_password) {
    client.call("update_user", username, password, new_username, new_password);
}


//OSCAR's CODE ADAPTED BY ADAM: Oscar, feel free to adjust and change if u have a way which matches smth u prefer to use.
vector ingredient_to_vector(Ingredient &ingr) { //returns vector as [name, quantity, category, expiry_date, priority_level], all as string s.
    vector vec;
    vec.push_back(ingr.name);
    vec.push_back(ingr.quantity);
    string cat_string = nameof(ingr.category); //gives the enum to string format.
    vec.push_back(cat_string);
    vec.push_back(ingr.expiry_date);
    string priority_level_string = nameof(ingr.priority_level);
    vec.push_back(ingr.priority_level);
    return vec;
}

Ingredient ingredient_from_vector(vector) { //Oscar work yo magic
    
}

Fridge ServerUser::get_fridge() {
    vector<vector<string>> fridge_vector = client.call("get_fridge", username, password); //vector of ingredients, each as a vector of strings.
    //Oscar work yo magic
}


void ServerUser::update_fridge(Fridge &f_input) {
    //convert to database-wanted format: OSCAR'S METHOD
    vector<vector<string>> fridge;
    for (list<Ingredient>::iterator i = f_input.ingredient_list.begin(); i != f_input.ingredient_list.end(); i++) {
        
        //convert ingredient to vector format USING OSCAR's CODE
        vector<string> ingredient;
        fridge.push_back(ingredient_to_vector(ingredient));
    }
    //send as new format
    client.call("update_fridge", username, password, fridge_vector);
}



list<Offer> ServerUser::get_offer_list() {
    vector<vector<vector<string>>> offer_list_vector = client.call("get_offer_list", username, password);
    //Oscar work yo magic: ADDED DETAIL: The offer list format holds offers, each other has this format exactly: [vector<string>, vector<string>], Where the second vector stores only a double!
    //That double represents the price of the offer. We needed this because vectors have homogenous type. (only store one type.)
    
}

void ServerUser::update_offer_list(list<Offer> &offer_list) {
    //Oscar work yo magiiiic: same format as get_offer_list for the data we want to give to the server.
    
    
    client.call("update_offer_list", username, password, new_offer_list); //this in the weird new vector<vector<vector<string>>> format, sorry! Check telegram paper image n1 for clarity, hopefully :)
}






