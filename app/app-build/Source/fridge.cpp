#include "../Header/fridge.h"

//#include <iostream>
//#include <list>
//#include <ctime>
//#include <chrono>
//using namespace std;

//FRIDGE

Fridge::Fridge(){
    ingredient_list = {};
}

Fridge::Fridge(std::vector<Ingredient> init_list){
    ingredient_list = init_list;
}

Fridge::~Fridge(){
}

void Fridge::set_list(std::vector<Ingredient> new_list){
    ingredient_list = new_list;
}

std::vector<Ingredient> Fridge::get_list(){
    return ingredient_list;
}

void Fridge::add_elt(Ingredient elt){
    ingredient_list.push_back(elt);
}

// Function to remove an ingredient from the vector
Ingredient Fridge::pop_elt(Ingredient *getit) {
    // Check if getit is nullptr
    if (getit == nullptr) {
        throw std::invalid_argument("Null pointer passed to pop_elt");
    }

    for (auto it = ingredient_list.begin(); it != ingredient_list.end(); ++it) {
        if (*it == *getit) {
            Ingredient foundIngredient = *it;
            ingredient_list.erase(it);
            return foundIngredient;
        }
    }

    throw std::runtime_error("Ingredient not found in the fridge");
}

#include <algorithm> // for std::sort

// ... [existing implementations]

// Function to sort ingredients by category
std::vector<Ingredient> Fridge::sort_ingredients_by_category() {
    std::vector<Ingredient> sorted_list = ingredient_list;
    std::sort(sorted_list.begin(), sorted_list.end(),
              [](Ingredient& a, Ingredient& b) {
                  return a.get_food_class_name() < b.get_food_class_name();
              }
              );
    return sorted_list;
}

// Function to sort ingredients by expiration date
std::vector<Ingredient> Fridge::sort_ingredients_by_expiration_date() {
    std::vector<Ingredient> sorted_list = ingredient_list;
    std::sort(sorted_list.begin(), sorted_list.end(),
              [](Ingredient& a, Ingredient& b) {
                  return a.get_expiry_date() < b.get_expiry_date();
              }
              );
    return sorted_list;
}
