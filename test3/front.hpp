#ifndef FRONT_HPP
#define FRONT_HPP
// Front end class definitions
#include <iostream>
#include <list>
#include <string>
#include <ctime>
//#include "nlohmann/json.hpp"
//using json = nlohmann::json;
using namespace std;


enum Food_class{
    fruit,
    vegetable,
    drink,
    dairy,
    canned,
    meat,
    fish,
    sweet,
    nut,
    unspecified,
    other
};

enum Priority{
    red,
    orange,
    green
};

////////////////////////////////////////////////////////////////////////////


class Date {
public:
    // Constructor with current date
    Date();
    Date(int d, int m, int y);
    void displayDate();
    int get_day();
    void set_day(int d);
    int get_month();
    void set_month(int m);
    int get_year();
    void set_year(int y);
    bool operator<(const Date& other) const;
    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    int is_exp_date();
    bool isLeapYear(int y) const;
    int countDays() const;

private:
    int day;
    int month;
    int year;
};

////////////////////////////////////////////////////////////////////////////

class Ingredient{
public:
    Ingredient(std::string name, int quantity = 1,Food_class category = unspecified, Date expiry_date);
    ~Ingredient();
    std::string get_name() const;
    bool operator==(const Ingredient& other) const;
    void set_FoodClass(Food_class category);
    Food_class get_food_class();
    std::string get_food_class_name();
    void set_quantity(int quantity);
    int get_quantity();
    void set_priority(Priority priority_level);
    Priority get_priority();
    std::string get_priority_name();
    void saveToJsonFile(const std::string& fileIngredient);
    void set_expiry_date(Date expiry_date);
    Date get_expiry_date();
    //json toJson () const;

private:
    std::string name;
    Food_class category;
    int quantity;
    Date expiry_date;
    Priority priority_level;
};

////////////////////////////////////////////////////////////////////////////

class Fridge {
public:
    Fridge();
    Fridge(std::vector<Ingredient> init_list);
    ~Fridge();
    void set_list(std::vector<Ingredient> new_list);
    std::vector<Ingredient> get_list();
    void add_elt(Ingredient elt);
    Ingredient pop_elt(Ingredient *getit);
    void saveToJsonFile(const std::string& fileFridge);
    void sort_fridge(std::string* sort_key);
    std::vector<Ingredient> sort_ingredients(std::string* sort_key);
    //json toJson () const;

private:
    std::vector<Ingredient> ingredient_list;
};

////////////////////////////////////////////////////////////////////////////

class Offer {
public:
    Offer(std::vector<Ingredient> ingredient_list);
    ~Offer();
    void set_price(double price);
    double get_price();
    //json toJson () const;

private:
    std::vector<Ingredient> ingredient_list;
    double price;
    // PHOTO

    // add filters in case don't want to see meat and other products
};

////////////////////////////////////////////////////////////////////////////

class User{
public:
    User(std::string username, std::string password);
    ~User();
    std::string get_username();
    bool check_password(std::string input_password);
    void set_telegram(std::string telegram);
    std::string get_telegram();
    //json toJson () const;

private:
    std::string username;
    std::string password;
    std::string telegram_username;
    Fridge user_fridge;
    std::list<Offer> offer_list;
};

#endif // FRONT_HPP
