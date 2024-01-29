#include "../Header/fridgemanager.h"
#include "../Header/date.h"
#include "../Header/offer.h"


#include <iostream>
#include <sstream>
#include <QDebug>
#include <iostream>
#include <list>

//-------Functions for std::strings to QString and Food_class -------
std::string convertQtoStd2(QString entry){
    std::string res;
    res = entry.toStdString();
    return res;
}

QString convertStdtoQ2(std::string entry){
    QString res = QString::fromStdString(entry);
    return res;
}

Food_class convertStringToFoodClass(const std::string& catString) {
    if (catString == "Unspecified") return Unspecified;
    else if (catString == "Fruit") return Fruit;
    else if (catString == "Vegetable") return Vegetable;
    else if (catString == "Drink") return Drink;
    else if (catString == "Dairy") return Dairy;
    else if (catString == "Canned") return Canned;
    else if (catString == "Meat") return Meat;
    else if (catString == "Fish") return Fish;
    else if (catString == "Sweet") return Sweet;
    else if (catString == "Nut") return Nut;
    else if (catString == "Other") return Other;

    // Default case if the category is not recognized
    return Unspecified;
}

//----- Main Code -----------------------------------------------

Fridge myFridge;
FridgeManager::FridgeManager(QObject *parent) : QObject(parent) {}

/*std::vector<Offer> my_offers;
void FridgeManager::
std::vector<Ingredient> offers_list;
Offer offer(offers_list);*/


void FridgeManager::add_elt(const QString &name, const QString &date, const QString &quantity, const QString &cat) {

    qDebug() << "Display Name:" << name;
    qDebug() << "Category:" << cat;

    std::string dateString = date.toStdString();                        //Date
    int parsedDay = std::stoi(dateString.substr(0, 2));                 //
    int parsedMonth = std::stoi(dateString.substr(3, 2));               //
    int parsedYear = std::stoi(dateString.substr(6, 4));                //

    std::cout << "Date:" << parsedDay << parsedMonth << parsedYear << std::endl;

    std::string nameitem = name.toStdString();                              //Name
    int quantityitem = quantity.toInt();                                    //Quantity
    Food_class catitem = convertStringToFoodClass(cat.toStdString());       //Category

    myFridge.add_elt(Ingredient(nameitem, Date(parsedDay, parsedMonth, parsedYear), quantityitem, catitem));

    std::cout << "Added an element to the fridge!" << std::endl;
}

Ingredient FridgeManager::pop_elt(const QString &nb) {
    int indice = nb.toInt();
    Ingredient* ingredientPtr = &myFridge.get_list()[indice];
    //std::cout << myFridge.get_list()[indice] << "ingredient" << std::endl;
    return myFridge.pop_elt(ingredientPtr);
}

void FridgeManager::clear(const QString &tt) {
    int nb = 0;
    for (int i = 0; i < tt.toInt(); i++) {
        pop_elt(0);
        nb++;
    }
    std::cout << nb << " item.s deleted" << std::endl;
}

//this one is useless
std::vector<Ingredient> FridgeManager::sort_ingredients_by_category() {
    return myFridge.sort_ingredients_by_category();
}


//----Function to sort the fridge by expiration date ------------------------------------------------
#include <QList>

QList<QList<QString>> FridgeManager::sort_ingredients_by_expiration_date() {
    std::vector<Ingredient> sortedIngredients = myFridge.sort_ingredients_by_expiration_date();

    QList<QList<QString>> result;

    for (Ingredient& ingredient : sortedIngredients) {
        QList<QString> ingredientInfo;
        ingredientInfo.append(convertStdtoQ2(ingredient.get_name()));                               // Name
        ingredientInfo.append(convertStdtoQ2(ingredient.get_expiry_date().Date::formateDate()));    // Date
        ingredientInfo.append(convertStdtoQ2(std::to_string(ingredient.get_quantity())));           // Quantity
        ingredientInfo.append(convertStdtoQ2(ingredient.get_food_class_name()));                    // Category

        result.append(ingredientInfo);
    }
    return result;
}

//----Function for the search bar ------------------------------------------------
QList<QList<QList<QString>>> FridgeManager::search_result(const QString &request) {
    std::vector<Ingredient> allIngredients = myFridge.sort_ingredients_by_expiration_date();  // Assuming you have a function to get all ingredients

    QList<QList<QString>> matchingIngredients;  // List for matching ingredients
    QList<QList<QString>> otherIngredients;     // List for non-matching ingredients

    QStringList searchTerms = request.split(" ", Qt::SkipEmptyParts);

    for (Ingredient& ingredient : allIngredients) {
        QList<QString> ingredientInfo;
        QString ingredientName = convertStdtoQ2(ingredient.get_name());

        // Check if any search term matches the ingredient name
        bool matches = false;
        for (const QString& term : searchTerms) {
            if (ingredientName.contains(term, Qt::CaseInsensitive)) {
                matches = true;
                break;
            }
        }

        if (matches) {
            // Add to matchingIngredients list
            ingredientInfo.append(ingredientName);  // Name
            ingredientInfo.append(convertStdtoQ2(ingredient.get_expiry_date().Date::formateDate()));  // Date
            ingredientInfo.append(convertStdtoQ2(std::to_string(ingredient.get_quantity())));         // Quantity
            ingredientInfo.append(convertStdtoQ2(ingredient.get_food_class_name()));                  // Category
            matchingIngredients.append(ingredientInfo);
        } else {
            // Add to otherIngredients list
            ingredientInfo.append(ingredientName);
            ingredientInfo.append(convertStdtoQ2(ingredient.get_expiry_date().Date::formateDate()));
            ingredientInfo.append(convertStdtoQ2(std::to_string(ingredient.get_quantity())));
            ingredientInfo.append(convertStdtoQ2(ingredient.get_food_class_name()));
            otherIngredients.append(ingredientInfo);
        }
    }

    QList<QList<QList<QString>>> result;
    result.append(matchingIngredients);
    result.append(otherIngredients);

    return result;
}




