#ifndef USER_H
#define USER_H

#include "fridge.h"
#include "offer.h"
#include "Signin.h"

//#include <iostream>
#include <list>
//#include <string>
//#include <ctime>
//#include "nlohmann/json.hpp"
//using json = nlohmann::json;
//using namespace std;

class User{
public:
    User(std::string username, std::string password, std::string telegram);
    ~User();
    std::string get_username();
    static bool check_password(std::string input_username, std::string input_password);
    void set_telegram(std::string telegram);
    static bool is_username(std::string username);
    std::string get_telegram();
    //json toJson () const;

private:
    std::string username;
    std::string password;
    std::string telegram_username;
    Fridge user_fridge;
    std::list<Offer> offer_list;

    //settings and preferences
    std::string restrictions;

};

#endif // USER_H
