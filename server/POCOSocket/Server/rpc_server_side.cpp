#include <iostream>
#include <string>
#include "rpc/server.h"
#include "rpc/this_session.h"
#include "rpc/this_handler.h"

using namespace std;

vector<string> food_list;
vector login_info; //login_info = [id, username, password, valid]
unordered_map<string, double> expiration_time; //expiration_time[food_name] = duration
int num_of_items;
unordered_map<string, vector> fridge; //fridge = {username:[id, food_name, time of remind(time of put in + expiration), calorie, valid,],username2:[..],...}

// We have two csv, one for login one for fridge
// columns of login database: id, username, password, valid(if the the account is still active)
// for fridge database: id, foodname, owner, calorie, valid(False if not in fridge or is expired)

void read_from_csv() {} //everytime open the server, read csv to get data from previous session

void save_to_csv() {} //save data of three maps in a csv

void add_food(unordered_map fridge, string food){}

void add_user(unordered_map login_info, string username, string password){}

void remove_user(unordered_map login_info){}

void remove_food(unordered_map fridge, food){}

string check_fridge(unordered_map fridge){}

unordered_map get_recommandation(){} //return a vector with vector[0] = name of dish, and the rest recipe

void reminder(){} // check regularly expiration whether shoud send notification

void remind_expiration (){} // send notification

void share_food(){} //push food from fridge to market place to the market

int main() {
    rpc::server srv(3333);

    srv.bind("add_food", &add_food);

    srv.bind("remove_food", &remove_food);

    srv.bind("add_user", &add_user);

    srv.bind("remove_user", &remove_user);

    srv.bind("get_recommandation", &get_recommandation);

    srv.bind("share_food", &share_food);

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
