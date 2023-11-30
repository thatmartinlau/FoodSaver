// Front end class definitions
#include <iostream>
#include <string>

Class User {
    public:
    User{};
    ~User{};

    private:
    std::string username;
    std::string password;
    std::string telegram_username;
    Fridge user_fridge;
};

Class Offer {
    public:
    Offer{};
    ~Offer{};

    private:
    std::list<Ingredient> ingredient_list;
    double price;
    User username;
    // PHOTO

    // add filters in case don't want to see meat and other products
};

Class Fridge {
    public:
    Fridge{};
    ~Fridge{};

    private:
    std::list<Ingredient> ingredient_list;
}

enum Food_class{
    fruit;
    vegetable;
    drink;
    dairy;
    canned;
    meat;
    fish;
    sweet;
    nut;
    other;
}

enum Priority{
    red;
    orange;
    green;
}

Class Ingredient{
    public:
    Ingredient{}
    ~Ingredient{}

    private:
    Food_class category;
    int quantity;
    std::string expiry_date;
    Priority_level priority;
}