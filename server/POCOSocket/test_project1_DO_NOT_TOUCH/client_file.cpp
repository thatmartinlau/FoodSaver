#include "common_characteristics.hpp"
#include "rpclib-master/include/rpc/client.h"


using namespace std;


string HOST_SERVER_NAME = "localhost"; //local connection first
int HOST_SERVER_PORT = 8080;

int main () {
    
    
    //test1: fridge sending/receiving:
    vector<string> ingr1 = {"name", "exp", "date", "cat1", "prior"};
    vector<vector<string>> fridge_test;
    fridge_test.push_back(ingr1);
    fridge_test.push_back(ingr1);
    //send through to server
    rpc::client new_cli(HOST_SERVER_NAME, HOST_SERVER_PORT);
    new_cli.call("test_sending_ingredient_vector_edition", ingr1);
    new_cli.call("test_sending_fridge_vector_edition", fridge_test);
    
    
}
