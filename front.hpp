#ifndef FRONT_HPP
#define FRONT_HPP
// Front end class definitions
#include <iostream>
#include <list>
#include <string>


enum Food_class{
    fruit,
    vegetable,
    drink,
    dairy,
    canned,
    meat,
    fish,
    sweet,
    nut,
    other
};

enum Priority{
    red,
    orange,
    green
};

class Ingredient{
public:
    Ingredient(){};
    ~Ingredient();
    void set_FoodClass(){};
    Food_class get_FoodClass(){};

private:
    Food_class category;
    int quantity;
    std::string expiry_date;
    Priority priority_level;
};

class Fridge {
public:
    Fridge(){};
    ~Fridge(){};

private:
    std::list<Ingredient> ingredient_list;
};

class User{
public:
    User(){};
    ~User(){};

private:
    std::string username;
    std::string password;
    std::string telegram_username;
    Fridge user_fridge;
};

class Offer {
public:
    Offer(){};
    ~Offer(){};

private:
    std::list<Ingredient> ingredient_list;
    double price;
    User username;
    // PHOTO

    // add filters in case don't want to see meat and other products
};

#endif // FRONT_HPP
