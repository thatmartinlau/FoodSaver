#ifndef FRONT_HPP
#define FRONT_HPP
// Front end class definitions
#include <iostream>
#include <list>
#include <string>


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

class Ingredient{
public:
    Ingredient();
    Ingredient(int quantity,Food_class category, std::string expiry_date);
    ~Ingredient();
    void set_FoodClass(Food_class category);
    Food_class get_FoodClass();
    void set_Quantity(int quantity);
    int get_Quantity();
    void set_priority(Priority priority_level);
    Priority get_priority();


private:
    Food_class category;
    int quantity;
    std::string expiry_date;
    Priority priority_level;
};

class Fridge {
public:
    Fridge();
    Fridge(std::list<Ingredient> init_list);
    ~Fridge();
    void set_list(std::list<Ingredient> new_list);
    std::list<Ingredient> get_list();
    void add_elt(Ingredient elt);
    Ingredient pop_elt();

private:
    std::list<Ingredient> ingredient_list;
};

class User{
public:
    User();
    ~User();
    void set_username(std::string username);
    std::string get_username();
    void set_password(std::string password);
    std::string get_password();
    void set_telegram(std::string telegram);
    std::string get_telegram();

private:
    std::string username;
    std::string password;
    std::string telegram_username;
    Fridge user_fridge;
};

class Offer {
public:
    Offer();
    ~Offer();
    void set_price(double price);
    double get_price();
    void set_user(User user);
    User get_user();

private:
    std::list<Ingredient> ingredient_list;
    double price;
    User username;
    // PHOTO

    // add filters in case don't want to see meat and other products
};

#endif // FRONT_HPP
