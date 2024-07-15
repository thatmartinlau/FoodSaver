#ifndef RPC_CLIENT_SIDE
#define RPC_CLIENT_SIDE

#include <iostream>
#include "common_characteristics.hpp"
#include "rpc/client.h"
#include "ingredient.h"
#include "date.h"
#include "fridge.h"
#include "offer.h"
#include "user.h"
string HOST_SERVER_NAME = "localhost"; //local connection first
int HOST_SERVER_PORT = 8080;

//ServerUser is a PARAMETER under the User class, from Sixtine's user.h

class ServerUser {
               
public:
    
//Creates a user for temporary Use.
    ServerUser(std::string username, std::string psswd);//if user doesn't exist in database, add him to database.
    ~ServerUser();

    void delete_self_in_db(); //deletes the user from the database.
    void update_user_password_and_username(std::string new_username, std::string new_password); //gives new username and password to database.
    
    
    User get_all_user_characs(string username, string password); //TO CODE, not urgent. Easy: return all user data    
    Fridge get_fridge(); //receives the fridge from the database.
    std::vector<Offer> get_offer_list(); //gets db's offer list for user
    
    void update_user_characteristics(User usr); //updates user's characteristics, ASIDE from username/password. that's update+user.    
    void update_fridge(Fridge &f_input); //updates the fridge on the database. Adds/removes necessary items with comparisons. Keeps the local fridge unchanged.
    void update_offer_list(vector<Offer> &offer_list); //updates db's offer list.
    
private:
    std::string username;
    std::string password;
};


vector<string> get_user_name_list();
double check_user(); //for William, no functionassociated here. Just to let u guys know ts already named away. Not to copy, or use anywhere.

#endif
