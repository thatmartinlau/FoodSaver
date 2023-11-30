#include "front.hpp"
#include <iostream>
#include <list>
using namespace std;

Ingredient::Ingredient(){
    this->category = unspecified;
    this->quantity = 1;
}

Ingredient::Ingredient(int quantity, Food_class category, string expiry_date){
    this->quantity = quantity;
    this->category = category;
    this->expiry_date = expiry_date;
}

Ingredient::~Ingredient(){

}

void Ingredient::set_FoodClass(Food_class category){
    this->category = category;
}

Food_class Ingredient::get_FoodClass(){
    return this->category;
}

void Ingredient::set_Quant(int quantity){
    this->quantity = quantity;
}

int Ingredient::get_Quant(){
    return this->quantity;
}

void Ingredient::set_priority(Priority priority_level){
    this->priority_level = priority_level;
}

Priority Ingredient::get_priority(){
    return this->priority_level;
}





