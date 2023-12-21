#include "front.hpp"
#include <iostream>
#include <list>
using namespace std;

//INGREDIENT

Ingredient::Ingredient(string *name){
    this->name = name;

    Food_class* cat = new Food_class;
    *cat = unspecified;
    this->category = cat;

    int* quant = new int;
    *quant = 1;
    this->quantity = quant;
}

Ingredient::Ingredient(string *name, int *quantity, Food_class *category, string *expiry_date){
    this->name = name;
    this->quantity = quantity;
    this->category = category;
    this->expiry_date = expiry_date;
}

Ingredient::~Ingredient() {
    delete name;
    delete category;
    delete quantity;
    delete expiry_date;
    delete priority_level;
}

string Ingredient::get_name() const {
    return *name;
}

bool Ingredient::operator==(const Ingredient& other) const {
    return (this->get_name() == other.get_name());
}

void Ingredient::set_FoodClass(Food_class *category){
    this->category = category;
}

Food_class Ingredient::get_FoodClass(){
    return *category;
}

void Ingredient::set_Quantity(int *quantity){
    this->quantity = quantity;
}

int Ingredient::get_Quantity(){
    return *quantity;
}

void Ingredient::set_priority(Priority *priority_level){
    this->priority_level = priority_level;
}

Priority Ingredient::get_priority(){
    return *priority_level;
}

//FRIDGE

Fridge::Fridge(){
    list<Ingredient> l = {};
    *ingredient_list = l;
}

Fridge::Fridge(list<Ingredient> init_list){
    *ingredient_list = init_list;
}

Fridge::~Fridge(){
    delete ingredient_list;
}

void Fridge::set_list(std::list<Ingredient> new_list){
    *ingredient_list = new_list;
}

list<Ingredient> Fridge::get_list(){
    return *ingredient_list;
}

void Fridge::add_elt(Ingredient elt){
    this->get_list().push_back(elt);
}

Ingredient Fridge::pop_elt(Ingredient *getit){
    this->get_list().remove(*getit);
    return *getit;
}

//USER
User::User(std::string *username, std::string *password) {
    this->username = username;
    this->password = password;
}

User::~User() {
    delete username;
    delete password;
    delete telegram_username;
    delete user_fridge;
}

std::string User::get_username() {
    return *username;
}

bool User::check_password(std::string *input_password) {
    return *input_password == *password;
}

void User::set_telegram(std::string *telegram) {
    telegram_username = telegram;
}

std::string User::get_telegram() {
    return *telegram_username;
}

//OFFER
Offer::Offer(std::list<Ingredient> *ingredient_list) {
    this->ingredient_list = ingredient_list;
    *price = (double) 0;
}

Offer::~Offer() {
    delete ingredient_list;
    delete price;
}

void Offer::set_price(double *price) {
    this->price = price;
}

double Offer::get_price() {
    return *price;
}
