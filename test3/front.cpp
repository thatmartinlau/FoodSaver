#include "front.hpp"
#include <iostream>
#include <list>
#include <ctime>
using namespace std;

// DATE

// By default, construct with current time

Date::Date() {
    time_t t = time(0);   // Get current time
    tm* now = localtime(&t);

    day = now->tm_mday;
    month = now->tm_mon + 1;  // tm_mon is zero-based
    year = now->tm_year + 1900;  // tm_year is years since 1900
}


Date::Date(int d, int m, int y) : day(d), month(m), year(y){

}

void Date::displayDate() {
    std::cout << "Date: " << year << '-' << month << '-' << day << std::endl;
}

int Date::get_day() {
    return day;
}

int Date::get_month() {
    return month;
}

int Date::get_year() {
    return year;
}

// Overload the < operator
bool Date::operator<(const Date& other) const {
    if (year < other.year)
        return true;
    if (year > other.year)
        return false;
    if (month < other.month)
        return true;
    if (month > other.month)
        return false;
    return day < other.day;
}

// Overload the == operator
bool Date::operator==(const Date& other) const {
    return day == other.day && month == other.month && year == other.year;
}

// Overload the != operator
bool Date::operator!=(const Date& other) const {
    return !(*this == other); // Utilize the == operator
}

//INGREDIENT

Ingredient::Ingredient(string name){
    this->name = name;

    Food_class cat;
    cat = unspecified;
    this->category = cat;

    int quant = 1;
    this->quantity = quant;
}

Ingredient::Ingredient(string name, int quantity, Food_class category, Date expiry_date){
    this->name = name;
    this->quantity = quantity;
    this->category = category;
    this->expiry_date = expiry_date;
}

Ingredient::~Ingredient() {
}

string Ingredient::get_name() const {
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

//USER
User::User(std::string username, std::string password) {
    this->username = username;
    this->password = password;
}

User::~User() {
}

std::string User::get_username() {
    return username;
}

bool User::check_password(std::string input_password) {
    return input_password == password;
}

void User::set_telegram(std::string telegram) {
    telegram_username = telegram;
}

std::string User::get_telegram() {
    return telegram_username;
}

//OFFER
Offer::Offer(std::list<Ingredient> ingredient_list) {
    this->ingredient_list = ingredient_list;
    price = (double) 0;
}

Offer::~Offer() {
}

void Offer::set_price(double price) {
    this->price = price;
}

double Offer::get_price() {
    return price;
}
