#ifndef FRIDGE_H
#define FRIDGE_H

#include "ingredient.h"


#include <vector>

class Fridge {
public:
    Fridge();
    Fridge(std::vector<Ingredient> init_list);
    ~Fridge();
    void set_list(std::vector<Ingredient> new_list);
    std::vector<Ingredient> get_list();
    void add_elt(Ingredient elt);
    Ingredient pop_elt(Ingredient *getit);
    //void sort_fridge(std::string* sort_key);
    std::vector<Ingredient> sort_ingredients_by_category();
    std::vector<Ingredient> sort_ingredients_by_expiration_date();

private:
    std::vector<Ingredient> ingredient_list;
};

#endif // FRIDGE_H
