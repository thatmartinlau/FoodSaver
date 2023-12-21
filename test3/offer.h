#ifndef OFFER_H
#define OFFER_H

#include "ingredient.h"

#include <iostream>
#include <list>
#include <string>
#include <ctime>
//#include "nlohmann/json.hpp"
//using json = nlohmann::json;
using namespace std;

class Offer {
public:
    Offer(std::vector<Ingredient> ingredient_list);
    ~Offer();
    void set_price(double price);
    double get_price();
    //json toJson () const;

private:
    std::vector<Ingredient> ingredient_list;
    double price;
    // PHOTO

    // add filters in case don't want to see meat and other products
};

#endif // OFFER_H
