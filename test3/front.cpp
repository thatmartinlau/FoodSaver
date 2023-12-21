#include "front.hpp"
#include <iostream>
#include <list>
#include <ctime>
#include <chrono>
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

void Date::set_day(int d) {
    this->day = d;
}

int Date::get_month() {
    return month;
}

void Date::set_month(int m) {
    this->month = m;
}

int Date::get_year() {
    return year;
}

void Date::set_year(int y) {
    this->year = y;
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

bool Date::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int Date::countDays() const {
    // Days in each month
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Count the days from years
    int totalDays = year * 365 + (year / 4) - (year / 100) + (year / 400);

    // Count the days from months
    for (int m = 0; m < month - 1; ++m) {
        totalDays += monthDays[m];
    }

    // Adding days of the current month
    totalDays += day;

    // Correct for leap year if the current year is a leap year and the date is after February
    if (month > 2 && isLeapYear(year)) {
        totalDays += 1;
    }

    return totalDays;

}

// returns 0 if today is the exp_day
// returns -1 if the exp date has passed
// returns the number of days until the
int Date::is_exp_date() {
    // Get the current date
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm* now_tm = std::localtime(&now_c);

    int today_day = now_tm->tm_mday;
    int today_month = now_tm->tm_mon + 1; // tm_mon is months since January (0-11)
    int today_year = now_tm->tm_year + 1900; // tm_year is years since 1900

    // Check if the date has passed
    if (this->year < today_year ||
        (this->year == today_year && this->month < today_month) ||
        (this->year == today_year && this->month == today_month && this->day < today_day)) {
        return -1;
    }

    // Check if the date is today
    else if (this->day == today_day && this->month == today_month && this->year == today_year) {
        return 0;
    }

    // If the date is in the future
    else {
        return 1
    }

    /*
    time_t t = time(0);   // Get current time
    tm* now = localtime(&t);
    int today_day = now->tm_mday;
    int today_month = now->tm_mon + 1;
    int today_year = now->tm_year + 1900;
    if (day == today_day && month == today_month && year == today_year) {
        return 0;
    }
    else if (day < today_day || month < today_month && year < today_year) {
        return -1;
    }
    else {
        int diff_day = 0;
        int diff_month = 0;
        int diff_year = 0;
        for (i = today_year; i ++; i < year) {
            if (i % 4 == 0) {
                diff_year += 366;
            }
            else {
                diff_year += 365;
            }
        }
        if (today_month > month) {

        }
        else {
            today_yeat
        }
        for (i = today_month; i ++; i <= month) {

        }
        if (month == today_month && year == today_year) {
            return day - today_day;
        }
        else {
            return -2;
        }
    }
*/
}

////////////////////////////////////////////////////////////////////////////

//INGREDIENT

Ingredient::Ingredient(string name, int quantity = 1, Food_class category = unspecified, Date expiry_date){
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

////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////

//OFFER
Offer::Offer(std::vector<Ingredient> ingredient_list) {
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
