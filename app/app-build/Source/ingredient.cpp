#include "../Header/ingredient.h"
#include <vector>
#include <string>
//#include <iostream>
//#include <list>
//#include <ctime>
//#include <chrono>
//using namespace std;

//INGREDIENT


Ingredient::Ingredient(std::string name, Date expiry_date, int quantity, Food_class category){
    this->name = name;
    this->quantity = quantity;
    this->category = category;
    this->expiry_date = expiry_date;
}

Ingredient::~Ingredient() {
}

std::string Ingredient::get_name() const {
    return name;
}

bool Ingredient::operator==(const Ingredient& other) const {
    return (this->get_name() == other.get_name());
}

void Ingredient::set_FoodClass(Food_class category){
    this->category = category;
}

Food_class Ingredient::get_food_class(){
    static const std::string foodClassNames[] = {
        "fruit", "vegetable", "drink", "dairy", "canned",
        "meat", "fish", "sweet", "nut", "unspecified", "other"
    };
    return category;
}

std::string Ingredient::get_food_class_name() {
    static const std::string foodClassNames[] = {
        "fruit", "vegetable", "drink", "dairy", "canned",
        "meat", "fish", "sweet", "nut", "unspecified", "other"
    };
    return foodClassNames[category];
}

void Ingredient::set_quantity(int quantity){
    this->quantity = quantity;
}

int Ingredient::get_quantity(){
    return quantity;
}

void Ingredient::set_priority(Priority priority_level){
    this->priority_level = priority_level;
}

Priority Ingredient::get_priority(){
    return priority_level;
}

std::string Ingredient::get_priority_name() {
    static const std::string priorityNames[] = {
        "red", "orange", "green"
    };
    return priorityNames[priority_level];
}

void Ingredient::set_expiry_date(Date expiry_date) {
    this->expiry_date = expiry_date;
}

Date Ingredient::get_expiry_date() {
    return expiry_date;
}
