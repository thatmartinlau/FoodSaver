#include <QCoreApplication>
#include <iostream>
#include "front.hpp"


int main(int argc, char *argv[])
{
    std::string ingredientName = "salmon";
    Ingredient ingredientInstance(ingredientName);

    std::string ingredientName2 = "broccoli";
    int ingredientQuantity = 5;
    Food_class ingredientCategory =  vegetable;
    Date date;
    Ingredient ingredientInstance2(ingredientName2, ingredientQuantity, ingredientCategory, date);

    ingredientInstance.set_FoodClass(fish);
    Date c = ingredientInstance2.get_expiry_date();
    std::cout << c.get_day() << "/" << c.get_month() << "/" << c.get_year() <<  std::endl;
    std::cout << "Hello" << std::endl;

    return 0;
}
