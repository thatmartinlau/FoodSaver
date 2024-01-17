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
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    val1 = test_send_vec_string();
    
    
    return a.exec();
}
