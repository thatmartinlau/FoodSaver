#ifndef INGREDIENT_H
#define INGREDIENT_H

#include "date.h"

//#include <iostream>
//#include <list>
//#include <string>
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
    Ingredient();
    Ingredient(std::string name, Date expiry_date, int quantity = 1,Food_class category = unspecified);
    ~Ingredient();
    std::string get_name() const;
    bool operator==(const Ingredient& other) const;
    void set_FoodClass(Food_class category);
    Food_class get_food_class();
    std::string get_food_class_name();
    void set_quantity(int quantity);
    int get_quantity();
    void set_priority();
    Priority get_priority();
    std::string get_priority_name();
    void saveToJsonFile(const std::string& fileIngredient);
    void set_expiry_date(Date expiry_date);
    Date get_expiry_date();
    int countDays();
    //json toJson () const;

private:
    std::string name;
    Food_class category;
    int quantity;
    Date expiry_date;
    Priority priority_level;
};

#endif // INGREDIENT_H
