/*
#include "front.hpp"
#include <iostream>
#include <list>
#include <ctime>
#include <chrono>
using namespace std;


std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
std::tm* date = std::localtime(&now);

Ingredient::Ingredient(int quantity, std::string expiry_date) : quantity(quantity), expiry_date(expiry_date), color("green") {}

bool Ingredient::expiration() {
    std::tm expiry_tm = {};
    std::istringstream ss(expiry_date);
    ss >> std::get_time(&expiry_tm, "%d-%m-%Y");
    
    if (date->tm_mday == expiry_tm.tm_mday && date->tm_mon + 1 == expiry_tm.tm_mon + 1 && date->tm_year + 1900 == expiry_tm.tm_year + 1900)
        return true;
    return false;
}

int Ingredient::counter() {
    std::tm expiry_tm = {};
    std::istringstream ss(expiry_date);
    ss >> std::get_time(&expiry_tm, "%d-%m-%Y");
    
    std::chrono::system_clock::time_point expiry_point = std::chrono::system_clock::from_time_t(std::mktime(&expiry_tm));
    std::chrono::duration<int> days_left = std::chrono::duration_cast<std::chrono::duration<int>>(expiry_point - std::chrono::system_clock::now());
    
    return days_left.count() / (60 * 60 * 24); // Convert seconds to days
}

void Ingredient::set_color() {
    int days_left = counter();
    
    if (days_left <= 7) {
        color = "yellow";
        if (days_left <= 2) {
            color = "red";
        }
    }
}

Fridge::Fridge(std::list<std::string> ingredients) : ingredients(ingredients) {}

Recipe::Recipe(std::string name, int number, std::list<std::string> ingredients, std::string restriction, std::string instructions)
    : name(name), number(number), ingredients(ingredients), restriction(restriction), instructions(instructions) {}

std::list<int> findRecipes(const std::string& ingredient, const Fridge& fridge) {
    std::list<int> recipe_nums;

    // Logic to find recipes based on ingredient and fridge

    return recipe_nums;
}


//USER

////////////////////////////////////////////////////////////////////////////

//OFFER
*/
