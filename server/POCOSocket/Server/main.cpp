#include <iostream>
#include <string>
#include <algorithm>
#include "rpc/server.h"

std::vector<std::string> *USER_LIST = new std::vector<std::string>;
std::vector<std::string> *PASSWORD_LIST = new std::vector<std::string>;
std::vector<std::string> *ONLINE_USERS = new std::vector<std::string>;



// Creates all necessary functions for client-side data to be sent/received:
bool addUser(std::vector<std::string> &login_details) {
    std::string username = login_details[0];
    std::string password = login_details[1];
    
    if (std::find(USER_LIST->begin(), USER_LIST->end(), username) != USER_LIST->end()) {//elt in list
        return false; //means user already in list
    }
    else {
        USER_LIST->push_back(username);
        PASSWORD_LIST->push_back(password);
        return true;
    }
}

bool openSession(std::vector<std::string> *login_details) {
    
}

bool closeSession(std::vector<std::string> *login_details) {
    
}

//Necessary server-side functions




//Main loop actually runs server
int main() {
    rpc::server srv(8080);
    std::vector<std::string> login;
    login.push_back("Johnny");
    login.push_back("admin");
    addUser(login);
    std::cout << (*USER_LIST)[0] << std::endl;
    std::cout << (*PASSWORD_LIST)[0] << std::endl;
    std::cout << "YOOO" << std::endl;
    
    srv.run();
    
    return 0;
}
