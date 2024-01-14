#ifndef RPC_CLIENT_SIDE
#define RPC_CLIENT_SIDE

#include <iostream>
#include "rpclib-master/include/rpc/client.h"
#include "Header/front.hpp"
#include "Header/ingredient.h"
#include "Header/date.h"
#include "Header/fridge.h"
#include "Header/offer.h"
#include "Header/user.h"


//Backend guys make a new user, which asks for functions to be called from serverside! All functions here are focused on getting server-coded functions called.
//Client connection:
//The class User from front.cpp would have a private variable serverUser belonging to this class.
//On every call which requests or requires, or gives data to the server database, simply call the sending/receiving functions given down here.

class ServerUser {
    
public:
    
    //Creates a user for temporary Use.
    ServerUser(std::string username, std::string psswd);//if user doesn't exist in database, add him to database.
    ~ServerUser();
    
    void delete_self_in_db(); //deletes the user from the database.
    
    Fridge get_fridge(); //receives the fridge from the database.
    void update_fridge(Fridge &f_input); //updates the fridge on the database. Adds/removes necessary items with comparisons. Keeps the local fridge unchanged.
    std::vector<Offer> get_offer_list(); //gets db's offer list for user
    void update_offer_list(vector<Offer> &offer_list); //updates db's offer list.
    void update_user(std::string new_username, std::string new_password); //gives new username and password to database.
    void update_user_characteristics(User usr); //updates user's characteristics, ASIDE from username/password. that's update+user.
    
private:
    std::string username;
    std::string password;
};


vector<string> get_user_name_list();

#endif
