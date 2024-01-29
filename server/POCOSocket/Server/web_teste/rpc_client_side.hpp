#ifndef RPC_CLIENT_SIDE
#define RPC_CLIENT_SIDE

#include <iostream>
#include "../common_characteristics.hpp"
#include "rpc/client.h"

#include "../../../../test3/ingredient.h"
#include "../../../../test3/date.h"
#include "../../../../test3/fridge.h"
#include "../../../../test3/offer.h"
#include "../../../../test3/user.h"



using namespace std;
//ServerUser is a PARAMETER under the User class, from Sixtine's user.h

class Ingredient;
class Date;
class Fridge;
class Offer;
class User;


class ServerUser {

public:
    //Creates a user for temporary Use.
    ServerUser();
    ServerUser(string username, string psswd);//if user doesn't exist in database, add him to database.
    ~ServerUser();

    string get_username(); // to use in get_all_ServerUser_characteristics
    string get_password(); // to use in get_all_ServerUser_characteristics


    basic_user_data get_basic_user_data();
    list<bool> get_food_restrictions();


    void delete_self_in_db(); //deletes the user from the database.
    void update_user_name_and_password(string new_username, string new_password); //gives new username and password to database.



    Fridge get_fridge(); //receives the fridge from the database.
    vector<Offer> get_offer_list(); //gets db's offer list for user

    void update_user_characteristics(User *usr); //updates user's characteristics, ASIDE from username/password. that's update+user.
    void update_food_restrictions(list<bool> food_restrictions);
    void update_fridge(Fridge &f_input); //updates the fridge on the database. Adds/removes necessary items with comparisons. Keeps the local fridge unchanged.
    void update_offer_list(vector<Offer> &offer_list); //updates db's offer list.

private:
    string username;
    string password;

};



unordered_map<string, vector<vector<vector<string>>>> //works :) below function works!! HEll yeas.
getOfferMapFromServer(); //works

vector<string> get_user_name_list();

vector<string> getAllRecipes();
void addRecipes(vector<string> recipes);

unordered_map<string, vector<vector<vector<string>>>> get_all_clients_with_offers();
vector<string> get_all_recipes();

int test_sending_to_db();
int test_getOfferMapFromServer();
int test_serveruser_call_destroy();
int testing_suite();

#endif
