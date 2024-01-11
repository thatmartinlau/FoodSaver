#ifndef FRIDGE_H
#define FRIDGE_H

//Antoine
#include <QObject>
#include <QString>

#include "ingredient.h"
#include <vector>
//#include <iostream>
//#include <list>
//#include <string>
//#include <ctime>

//#include "nlohmann/json.hpp"
//using json = nlohmann::json;
//using namespace std;

class Fridge {
//class Fridge : public QObject {
    //Q_OBJECT

public:
    //explicit Fridge(QObject *parent = nullptr);
    //explicit Fridge();

    //Q_INVOKABLE bool fridge();

    Fridge();
    Fridge(std::vector<Ingredient> init_list);
    ~Fridge();
    void set_list(std::vector<Ingredient> new_list);
    std::vector<Ingredient> get_list();
    void add_elt(Ingredient elt);
    Ingredient pop_elt(Ingredient *getit);
    void saveToJsonFile(const std::string& fileFridge);
    //void sort_fridge(std::string* sort_key);
    std::vector<Ingredient> sort_ingredients_by_category(std::string sort_key);
    std::vector<Ingredient> sort_ingredients_by_expiration_date(std::string sort_key);
    //json toJson () const;

private:
    std::vector<Ingredient> ingredient_list;


//signals:
    //void openMarketPage();
};

#endif // FRIDGE_H
