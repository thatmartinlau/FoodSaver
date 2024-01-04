#include <QCoreApplication>
#include <iostream>
#include "date.h"
#include "ingredient.h"
#include "fridge.h"
#include "offer.h"
#include "user.h"


int main(int argc, char *argv[])
{

    std::string ingredientName = "salmon";
    Date d;
    Food_class ct = fish;
    Ingredient ingredientInstance(ingredientName, d, 1, ct);

    std::string ingredientName2 = "broccoli";
    int ingredientQuantity = 5;
    Food_class ingredientCategory =  vegetable;
    Date date;
    date.set_day(19);
    Ingredient ingredientInstance2(ingredientName2, date, ingredientQuantity, ingredientCategory);

    std::string ingredientName3 = "aubergine";
    int q = 5;
    Food_class iC =  vegetable;
    Date da;
    da.set_day(16);
    Ingredient ingredientInstance3(ingredientName3, da, q, iC);

    Fridge f;
    f.add_elt(ingredientInstance2);
    f.add_elt(ingredientInstance);
    f.add_elt(ingredientInstance3);
    //std::cout << ingredientInstance.get_name() << " hi" << std::endl;
    //std::cout << f.get_list()[0].get_name() << std::endl;

    std::vector<Ingredient> v = f.get_list();
    //std::cout << f.get_list().size() << std::endl;
    Ingredient ing0 = v[0];
    //std::cout << "Hii" << std::endl;
    //std::cout << f.get_list()[0].get_name() << std::endl;
    for (int i = 0; i <= 3; i++) {
        std::cout << f.get_list()[i].get_name() << std::endl;
    }

    //ingredientInstance.set_FoodClass(fish);
    //Date c = ingredientInstance2.get_expiry_date();
    //std::cout << c.get_day() << "/" << c.get_month() << "/" << c.get_year() <<  std::endl;
    //std::cout << c.countDays() << std::endl;
    //std::cout << f.get_list()[0].get_name() << " hi" << std::endl;
    //std::cout << f.sort_ingredients_by_category() << std::endl;

    for (int i = 0; i <= 3; i++) {
        std::cout << f.sort_ingredients_by_expiration_date()[i].get_name() << std::endl;
    }

    std::cout << "Hello" << std::endl;

    return 0;
}
