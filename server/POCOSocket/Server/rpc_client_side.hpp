#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "rpclib-master/include/rpc/client.h"
#include "../../../test3/front.hpp"

using namespace std;

//Backend guys make a new user, which asks for functions to be called from serverside! All functions here are focused on getting server-coded functions called.
//Client connection:
//The class User from front.cpp would have a private variable serverUser belonging to this class.
//On every call which requests or requires, or gives data to the server database, simply call the sending/receiving functions given down here.


const string HOST_SERVER_NAME = "127.0.0.1"; //change to Server later.
const int HOST_SERVER_PORT = 3333;


class ServerUser {
               
public:
    
//Creates a user for temporary Use.
    ServerUser(string username, string psswd);//if user doesn't exist in database, add him to database.
    ~ServerUser();

    void delete_self_in_db(); //deletes the user from the database.
    
    Fridge get_fridge(); //receives the fridge from the database.
    void update_fridge(); //updates the fridge on the database. Adds/removes necessary items with comparisons. Keeps the local fridge unchanged.
    list<Offer> get_offer_list(); //gets db's offer list for user
    void update_offer_list(); //updates db's offer list.
    void update_user(string new_username, string new_password); //gives new username and password to database.
private:
    string username;
    string password;
};
