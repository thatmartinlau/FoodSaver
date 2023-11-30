#include "front.hpp"
#include <iostream>
#include <list>
using namespace std;

//INGREDIENT

Ingredient::Ingredient(){
    Food_class* cat = new Food_class;
    *cat = unspecified
    this->category = *cat;

    int* quant = new int;
    *quant = 1;
    this->quantity = *quant;
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

//FRIDGE

Fridge::Fridge(){
    this->ingredient_list = list<Ingredient>;
}

Fridge::Fridge(list<Ingredient> init_list){
    this->ingredient_list = init_list;
}

Fridge::~Fridge(){

}

void Fridge::set_list(std::list<Ingredient> new_list){
    this->ingredient_list = new_list;
}

list<Ingredient> Fridge::get_list(){
    return this->ingredient_list;
}

void Fridge::add_elt(Ingredient elt){
    this->get_list().push_back(elt);
}

Ingredient Fridge::pop_elt(){
    this->get_list().pop_front();
}

//USER




