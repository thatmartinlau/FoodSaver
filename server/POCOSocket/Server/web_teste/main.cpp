#include <QCoreApplication>

#include "common_characteristics.hpp"
#include "rpc/client.h"
using namespace std;
string HOST_SERVER_NAME = "localhost"; //local connection first
int HOST_SERVER_PORT = 8080;

int test_send_vec_string() {
    vector<string> vec_for_testing = {"ingredient_name", "ingr_dat", "ingr_qty", "ingr_cat", "ingr_prio_level"};
    rpc::client new_client(HOST_SERVER_NAME, HOST_SERVER_PORT);
    vector<string> returned_vec = new_client.call("test_sending_ingredient_as_vec", vec_for_testing).as<vector<string>>();
    cout << returned_vec[0] << endl;
    return 1;
}

int test_send_fridge_as_vec_vec_string() {
    vector<string> vec_for_testing_1 = {"ingredient_name", "ingr_dat", "ingr_qty", "ingr_cat", "ingr_prio_level"};
    vector<string> vec_for_testing_2 = {"apple", "ingr_dat", "3", "1", "REDD"};
    vector<vector<string>> fridge = {vec_for_testing_1, vec_for_testing_2};
    
    rpc::client new_client(HOST_SERVER_NAME, HOST_SERVER_PORT);
    vector<vector<string>> returned_vec = new_client.call("test_sending_fridge_as_vec", fridge).as<vector<vector<string>>>();
    cout << returned_vec[0][1] << " and second ingr: " << returned_vec[1][5] << endl;
    return 1;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout << "hello, it opens" << endl;
    int val1 = test_send_vec_string();
    int val2 = test_send_fridge_as_vec_vec_string();
    
    
    return a.exec();
}
