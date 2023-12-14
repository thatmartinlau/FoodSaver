#include <iostream>
#include "rpclib-master/include/rpc/client.h"
#include "../../../test3/front.hpp"


//Backend guys make a new user, which asks for functions to be called from serverside! All functions here are focused on getting server-coded functions called.
//Client connection:

class ServerUser {
               
public:
    
//Creates a user for temporary Use.
    ServerUser(std::string username, std::string psswd);
    ~ServerUser();

//createClient will add user data, login, to the server. Checks it isnt already in use, makes hash to give user so he can only access his own data.
//login details given as a list of 2 strings. 1 means user added, 0 means user not added.
    bool create_user();
    void remove_self();
    void add_food(Ingredient food); //quantities included already.
    void remove_food(Ingredient food);
    void share_food();
    void get_recommendation();
    Fridge get_fridge();
    void get_offer_list();
    void upload_offer();
private:
    rpc::client client;
    
    std::vector login_info; //[id, username, password, valid] //what is valid? How to compute id?
};
