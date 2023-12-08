#include <iostream>

#include "rpc/server.h"
#include "rpc/this_session.h"
#include "rpc/this_handler.h"

std::unordered_map<std::string, std::string> login_info; //login_info[username] = password
std::unordered_map<std::string, double> expiration_time; //expiration_time[food_name] = duration
std::unordered_map<std::string, std::unordered_map> fridge; //fridge[username][item] = time of put in

void read_from_csv() {} //everytime open the server, read csv to get data from previous session

void save_to_csv() {} //save data of three maps in a csv

void add_food(std::unordered_map fridge){}

void add_user(std::unordered_map login_info){}

void remove_user(std::unordered_map login_info){}

void remove_food(std::unordered_map fridge){}

std::string check_fridge(std::unordered_map fridge){}

std::unordered_map get_recommandation(){} //return a vector with vector[0] = name of dish, and the rest recipe

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
