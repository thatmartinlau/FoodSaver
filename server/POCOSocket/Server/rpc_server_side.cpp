#include <iostream>
#include <string>
#include "rpc/server.h"
#include "rpc/client.h"
#include "rpc/this_session.h"
#include "rpc/this_handler.h"

using namespace std;


int num_of_items;
unordered_map<string, vector>

// We have two csv, one for login one for fridge
// columns of login database: id, username, password, valid(if the the account is still active)
// for fridge database: id, foodname, owner, calorie, valid(False if not in fridge or is expired)

void read_from_csv() {} //everytime open the server, read csv to get data from previous session

void save_to_csv() {} //save data of the map in a csv


void update_fridge(std::string user_to_update, unordered_map updated_fridge) {} //updates a user fridge: replaces add/remove functions,
//important to implement this^ instead of add/remove only, for the offers. Makes it easier to implement later.


void add_user(unordered_map login_info){}

void remove_user(unordered_map login_info){}

void update_offer(std::string user_to_update, unordered_map updated_offer) {}//tell frontend to pay attention to update fridge here

unordered_map<string,vector> get_user_data(username) {}//combine get fridge, get offer

int main() {
    rpc::server srv(3333);
    
    srv.bind("update_fridge", &update_fridge);
    
    srv.bind("get_fridge", &get_fridge);

    srv.bind("add_user", &add_user);

    srv.bind("remove_user", &remove_user);
    
    srv.bind("add_offer", &add_offer);
    
    srv.bind("satisfy_offer_exchange", &satisfy_offer_exchange);
    
    srv.bind("delete_offer", &delete_offer);
    
    

    // template for error messages
    srv.bind("error", []() {
        auto err_obj = std::make_tuple(13, "Errors are arbitrary objects");
        rpc::this_handler().respond_error(err_obj);
    });

    // client connect, will respense first
    srv.bind("exit", []() {
        rpc::this_session().post_exit();
    });
        
    srv.run();
    

    return 0;
}
