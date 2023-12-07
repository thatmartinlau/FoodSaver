#include <iostream>
#include <string>
#include <algorithm>
#include "rpc/server.h"
#include "database.hpp" //important: we don't code the daatbase in main! :)

std::vector<std::string> *USER_LIST = new std::vector<std::string>;
std::vector<std::string> *PASSWORD_LIST = new std::vector<std::string>;



//we store JSON files as big strings, or LATER we can implement a library to be cleaner.
//the second vari points to a vector of strings ,i.e. a list of user''s json files.
std::map<std::string, std::vector<std::string>*> database; //indexed by user, contains lists which contain fridges, etc, offers, whatever we need to store.



//All necessary functions for client-side data to be sent/received:

bool addUser(std::vector<std::string> &login_details) {
    std::string username = login_details[0];
    std::string password = login_details[1];
    
    if (std::find(USER_LIST->begin(), USER_LIST->end(), username) != USER_LIST->end()) {//elt in list
        return false; //means user already in list
    }
    else {
        USER_LIST->push_back(username);
        PASSWORD_LIST->push_back(password);
        //open a database slot for the user
        std::vector<std::string> *new_list = new std::vector<std::string>;
        database[username] = new_list;
        return true;
    }
}

void addItem(std::vector<std::string> *login_details, std::string file) { //TEMPLATE for now, we imporve once we know which filetypes to store.
    database[login_details[0]]->push_back(file);
}

std::string retrieveItem(std::string itemName) {
    return database[login_details[0]]->itemName //this is broken, will work when we find a way to reference items by name.
    //TO do this, we can use a JSON parser in cpp, or we cn write our own functions to adapt oscar's functions to blabla, talk alter.
}


//Main loop runs server
int main() {
    rpc::server srv(8080);
    //bind the client-side functions to the server:
    srv.bind("addUser", &addUser); //check client-side.h & .cpp, to see how we call a binded function.
    srv.bind("addItem", &addItem);    
    
    srv.run();
    return 0;
}
