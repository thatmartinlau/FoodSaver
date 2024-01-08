#include <QCoreApplication>
#include <iostream>
#include "../Header/date.h"
#include "../Header/ingredient.h"
#include "../Header/fridge.h"
#include "../Header/offer.h"
#include "../Header/user.h"


int main(int argc, char *argv[])
{

    std::string ingredientName = "salmon";
    Date d;
    Ingredient ingredientInstance(ingredientName, d);

    std::string ingredientName2 = "broccoli";
    int ingredientQuantity = 5;
    Food_class ingredientCategory =  vegetable;
    Date date;
    date.set_day(19);
    Ingredient ingredientInstance2(ingredientName2, date, ingredientQuantity, ingredientCategory);

    ingredientInstance.set_FoodClass(fish);
    Date c = ingredientInstance2.get_expiry_date();
    std::cout << c.get_day() << "/" << c.get_month() << "/" << c.get_year() <<  std::endl;
    std::cout << c.countDays() << std::endl;
    std::cout << "Hello" << std::endl;

    return 0;
}
