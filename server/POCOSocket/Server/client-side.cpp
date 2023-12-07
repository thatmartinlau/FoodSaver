#include "rpc/client.h"
#include <string>


ServerUser::ServerUser(std::vector<std::string> *login_details) {
    this->login_details = login_details;
    
    //default: port is 8080, same as in main.cpp. Important to keep the same afaik.
    client = client(ip_address, 8080);
}

bool ServerUser::addUser() {
    bool worked = client.call("addUser", *login_details).as<bool>(); //obtains the result from server we called to.
    return worked;
}


