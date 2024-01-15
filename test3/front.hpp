#ifndef FRONT_HPP
#define FRONT_HPP
// Front end class definitions
#include <iostream>
#include <list>
#include <string>
#include <ctime>
#include <chrono>
#include<iomanip>

//#include "nlohmann/json.hpp"
//using json = nlohmann::json;

using namespace std;
#ifndef FRONT_HPP
#define FRONT_HPP



class Ingredient {
public:
    Ingredient(int quantity, std::string expiry_date);

    bool expiration();
    int counter();
    void set_color();

private:
    int quantity;
    std::string expiry_date;
    std::string color;
};

class Fridge {
public:
    Fridge(std::list<std::string> ingredients);

private:
    std::list<std::string> ingredients;
};

class Recipe {
public:
    Recipe(std::string name, int number, std::list<std::string> ingredients, std::string restriction, std::string instructions);

    // Add other required functionalities

private:
    std::string name;
    int number;
    std::list<std::string> ingredients;
    std::string restriction;
    std::string instructions;
};

std::list<int> findRecipes(const std::string& ingredient, const Fridge& fridge);

#endif // FRONT_HPP
