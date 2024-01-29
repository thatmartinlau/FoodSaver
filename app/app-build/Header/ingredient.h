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
    Unspecified,
    Fruit,
    Vegetable,
    Drink,
    Dairy,
    Canned,
    Meat,
    Fish,
    Sweet,
    Nut,
    Other
};

enum Priority{
    red,
    orange,
    green
};

class Ingredient{
public:
    Ingredient(){};
    Ingredient(std::string name, Date expiry_date, int quantity = 1,Food_class category = Unspecified);
    ~Ingredient();
    std::string get_name() const;
    bool operator==(const Ingredient& other) const;
    void set_FoodClass(Food_class category);
    Food_class get_food_class();
    std::string get_food_class_name();
    void set_quantity(int quantity);
    int get_quantity();
    void set_priority(Priority priority_level);
    Priority get_priority();
    std::string get_priority_name();
    void saveToJsonFile(const std::string& fileIngredient);
    void set_expiry_date(Date expiry_date);
    Date get_expiry_date();
    //json toJson () const;

private:
    std::string name;
    Food_class category;
    int quantity;
    Date expiry_date;
    Priority priority_level;
};

#endif // INGREDIENT_H
