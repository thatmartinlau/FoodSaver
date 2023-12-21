#include "fridge.h"

#include <iostream>
#include <list>
#include <ctime>
#include <chrono>
using namespace std;

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
    this->get_list().push_back(elt);
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
