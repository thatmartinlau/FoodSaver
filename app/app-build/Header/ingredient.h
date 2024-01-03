#ifndef INGREDIENT_H
#define INGREDIENT_H

#include "date.h"

//#include <iostream>
//#include <list>
#include <string>
//#include <ctime>


//#include "nlohmann/json.hpp"
//using json = nlohmann::json;
//using namespace std;

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
    unspecified,
    other
};

enum Priority{
    red,
    orange,
    green
};

class Ingredient{
public:
    //Ingredient class - for the items that users will enter into their fridges and market (entries and whatnot)
    Ingredient(std::string name, Date expiry_date, int quantity = 1,Food_class category = unspecified);
    ~Ingredient();

    //parameter functions
    void set_quantity(int quantity);
    void set_FoodClass(Food_class category);
    void set_expiry_date(Date expiry_date);
    void set_priority(Priority priority_level);

    std::string get_name() const;
    Date get_expiry_date();
    int get_quantity();
    Food_class get_food_class();
    std::string get_food_class_name();
    std::string get_priority_name();
    Priority get_priority();

    //operator overloading
    bool operator==(const Ingredient& other) const;

    //json functions
    void saveToJsonFile(const std::string& fileIngredient);
    //json toJson () const;

private:
    std::string name;
    Food_class category;
    int quantity;
    Date expiry_date;
    Priority priority_level;
};

#endif // INGREDIENT_H
