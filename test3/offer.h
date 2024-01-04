#ifndef OFFER_H
#define OFFER_H

#include "ingredient.h"
#include "user.h"

//#include <iostream>
//#include <list>
//#include <string>
//#include <ctime>
//#include "nlohmann/json.hpp"
//using json = nlohmann::json;
//using namespace std;

class Offer {
public:
    Offer();
    //Offer(Ingredient ingredient_on_offer);
    ~Offer();
    void set_price(double price);
    double get_price();
    void set_quantity(int q);
    int get_quantity();
    void set_ingredient(Ingredient i);
    Ingredient get_ingredient();

    void set_username(User username);
    User get_username();
    //json toJson () const;

    /*
    std::vector<Ingredient> sort_offers_by_category();
    std::vector<Ingredient> sort_offers_by_expiration_date();
    std::vector<Ingredient> sort_offers_by_price();
    */

private:
    Ingredient ingredient_on_offer;
    double price;
    int quantity;
    User username;
    // PHOTO

    // add filters in case don't want to see meat and other products
};

#endif // OFFER_H
