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

////////////////////////////////////////////////////////////////////////////

class Ingredient{
public:
    Ingredient(std::string *name);
    Ingredient(std::string *name, int *quantity,Food_class *category, std::string *expiry_date);
    ~Ingredient();
    std::string get_name() const;
    bool operator==(const Ingredient& other) const;
    void set_FoodClass(Food_class *category);
    Food_class get_FoodClass();
    void set_Quantity(int *quantity);
    int get_Quantity();
    void set_priority(Priority *priority_level);
    Priority get_priority();
    void saveToJsonFile(const std::string& fileIngredient);

private:
    std::string *name = new std::string;
    Food_class *category = new Food_class;
    int *quantity = new int;
    std::string *expiry_date = new std::string;
    Priority *priority_level = new Priority;
};

////////////////////////////////////////////////////////////////////////////

class Fridge {
public:
    Fridge();
    Fridge(std::list<Ingredient> init_list);
    ~Fridge();
    void set_list(std::list<Ingredient> new_list);
    std::list<Ingredient> get_list();
    void add_elt(Ingredient elt);
    Ingredient pop_elt(Ingredient *getit);
    void saveToJsonFile(const std::string& fileFridge);
    std::list<Ingredient> sort_ingredients(std::string* sort_key);

private:
    std::list<Ingredient>* ingredient_list = new std::list<Ingredient>;
};

////////////////////////////////////////////////////////////////////////////

class Offer {
public:
    Offer(std::list<Ingredient> *ingredient_list);
    ~Offer();
    void set_price(double *price);
    double get_price();

private:
    std::list<Ingredient>* ingredient_list = new std::list<Ingredient>;
    double* price = new double;
    // PHOTO

    // add filters in case don't want to see meat and other products
};

////////////////////////////////////////////////////////////////////////////

class User{
public:
    User(std::string *username, std::string *password);
    ~User();
    std::string get_username();
    bool check_password(std::string *input_password);
    void set_telegram(std::string *telegram);
    std::string get_telegram();

private:
    std::string* username = new std::string;
    std::string* password = new std::string;
    std::string* telegram_username = new std::string;
    Fridge* user_fridge = new Fridge();
    std::list<Offer>* offer_list = new std::list<Offer>;
    };

#endif // FRONT_HPP
