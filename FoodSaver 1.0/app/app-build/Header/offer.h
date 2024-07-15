#ifndef OFFER_H
#define OFFER_H

#include "ingredient.h"
//#include "user.h"

#include <vector>
//#include <iostream>
//#include <list>
//#include <string>
//#include <ctime>
//#include "nlohmann/json.hpp"
//using json = nlohmann::json;
//using namespace std;

class Offer {
public:
    Offer(std::vector<Ingredient> ingredient_list);
    ~Offer();
    void set_price(double price);
    double get_price();
    Ingredient get_ingredient();
    void set_ingredient(Ingredient ing);

    //json toJson () const;

private:
    std::vector<Ingredient> ingredient_list;
    Ingredient ingredient_on_offer;
    double price;
    // PHOTO

    // add filters in case don't want to see meat and other products
};

#endif // OFFER_H
