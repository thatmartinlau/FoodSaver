#include <iostream>
#include <string>
#include "rpc/server.h"
#include "rpc/client.h"
#include "rpc/this_session.h"
#include "rpc/this_handler.h"

using namespace std;

//FILE FORMATS:

//Ingredients: vector<string>>
//Fridge: vector<vector<string>>
//Offer: vector<vector<vector<string>>>: with vectors represented as {}, an offer looks like: { {Ingredient1, Ingredient2, etc}, {{price}} } where all elements are strings.
//Offer List: vector<vector<vector<vector<string>>>>, looking like {Offer1, Offer2, etc}.
//Database: unordered_map<string, UserData>, dicts as [], looking like  [username1: UserData, username2: UserData], with UserData having:

class UserData {
public:
    UserData(string password){
        this->password = password;
    };
    string password;
    vector<vector<string>> fridge;
    vector<vector<vector<vector<string>>>> offer_list;
};

unordered_map<string, UserData>* database = new unordered_map<string, UserData>;


//One CSV file, storing in a weird way adam will figure out.
void read_from_csv() {
    
} //everytime open the server, read csv to get data from previous session

void save_to_csv() {} //save data of the map in a csv

//DB Manipulation functions:
void add_user(string username, string password){
    if (database->find(username) == database->end()) {
        // Element doesn't exist, so add it
        UserData data(password);
        (*database)[username] = data;
    }
}

void remove_user(string username, string password){
    auto el = database->find(username); // Find the username in the database
    if (el != database->end()) {
        // Username exists
        if (password == el->second.password) {
            // Password matches
            database->erase(el); // Remove the user if the password matches
        } else {
            // Password does not match
        }
    } else {
        // Username not found
    }

}
void update_user(string old_username, string old_password, string new_username, string new_password) {
    auto el = database->find(old_username); // Find the username in the database
    if (el != database->end()) {
        // Username exists
        if (old_password == el->second.password) {
            // Password matches
            UserData data = el->second;
            database->erase(el);
            add_user(new_username, new_password);
            }
        }
    }//changes a user's name and password. Old is for login verification, new is to change.

void update_fridge(std::string username, string password, vector<vector<string>> new_fridge) {
        auto el = database->find(username); // Find the username in the database
        if (el != database->end()) {
            // Username exists
            if (password == el->second.password) {
                // Password matches
            el->second.fridge = new_fridge;
            }
        }
} //updates a user fridge

void update_offer(std::string username, string password, vector<vector<vector<vector<string>>>> new_offer) {
        auto el = database->find(username); // Find the username in the database
        if (el != database->end()) {
            // Username exists
            if (password == el->second.password) {
            // Password matches
            el->second.offer_list = new_offer;
            }
        }
} //updates a user offer list

//DB Sending Functions:
vector<vector<vector<vector<string>>>> get_offer_list(string username, string password) {
        auto el = database->find(username); // Find the username in the database
        if (el != database->end()) {
            // Username exists
            if (password == el->second.password) {
            // Password matches
            return el->second.offer_list;
            }
        }
}
vector<vector<string>> get_fridge(string username, string password) {
        auto el = database->find(username); // Find the username in the database
        if (el != database->end()) {
            // Username exists
            if (password == el->second.password) {
            // Password matches
            return el->second.fridge;
            }
        }
}

int main() {
    rpc::server srv(3333);
    
    //DB Manip
    srv.bind("add_user", &add_user);
    srv.bind("remove_user", &remove_user);
    srv.bind("update_user", &update_user);
    
    srv.bind("update_fridge", &update_fridge);
    srv.bind("update_offer", &update_offer);
    
    //DB Sending
    srv.bind("get_fridge", &get_fridge);
    srv.bind("get_offer_list", &get_offer_list);
    

    // template for error messages ::we keep this or not? To William, from Adam
    srv.bind("error", []() {
        auto err_obj = std::make_tuple(13, "Errors are arbitrary objects");
        rpc::this_handler().respond_error(err_obj);
    });

        
    srv.run();
    return 0;
}
