#include <iostream>
#include <string>
#include <vector>
#include <fstream>
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
    string password;
    vector<vector<string>> fridge;
    vector<vector<vector<vector<string>>>> offer_list;
};

unordered_map<string, UserData>* database = new unordered_map<string, UserData>;


//Storage format: username, password, fridge, offer;
//Inspired from iq.opengenus.org/read-and-write-in-csv-cpp/
void read_from_csv() { //everytime open the server, read csv to get data from previous session 
    ifstream file;
    file.open("database.csv");
    vector<string> lines;
    for (string line; getline(file, line);) {
        lines.push_back(line);
    }
    
    for (auto line : lines) {
        //comma-separate the lines into username, data format.
        stringstream s_line(line);
        
        vector<string>* temp_holder = new vector<string>;
        for (string item; getline(ss, item, ",");) {
            temp_holder->push_back(item);
        }
        //temp_holder looks like : [username, password, fridge, offer_list] afterwards. All strings.
        //convert fridge string "{[name: category: quantity: expiry_date: priority_level]; [...]; ...}"
        vector<vector<string>> fridge_updated;
        stringstream s_fridge(temp_holder[2]); //fridge
        for (string ) { //separate into Ingredients
            
        }
            
        //convert offer_list string "{[name: category: quantity: expiry_date: priority_level]; [...]; ...; price}"
            
        //create username and data:
        data = UserData();
        data.password = 
    }
    
}
    

void save_to_csv() {} //save data of the map in a csv

    

//DB Manipulation functions:
void add_user(string username, string password){} //adds user only if user not in already, needs to check for that here/
void remove_user(string username, string password){}
void update_user(string old_username, string old_password, string new_username, string new_password) {} //changes a user's name and password. Old is for login verification, new is to change.

void update_fridge(std::string username, vector<vector<string>> new_fridge) {} //updates a user fridge
void update_offer(std::string username, vector<vector<vector<string>>> new_offer) {} //updates a user offer list

//DB Sending Functions:
vector<vector<vector<string>>> get_offer_list(string username, string password) {}
vector<vector<string>> get_fridge(string username, string password) {}

int main2() {
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

int main() {
    
}
