#include "../Header/fridgemanager.h"
#include "../Header/date.h"

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
    if (catString == "unspecified") return unspecified;
    else if (catString == "fruit") return fruit;
    else if (catString == "vegetable") return vegetable;
    else if (catString == "drink") return drink;
    else if (catString == "dairy") return dairy;
    else if (catString == "canned") return canned;
    else if (catString == "meat") return meat;
    else if (catString == "fish") return fish;
    else if (catString == "sweet") return sweet;
    else if (catString == "nut") return nut;
    else if (catString == "other") return other;

    // Default case if the category is not recognized
    return unspecified;
}

//----- Main Code -----------------------------------------------

Fridge myFridge;
FridgeManager::FridgeManager(QObject *parent) : QObject(parent) {}

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

Ingredient FridgeManager::pop_elt(Ingredient *getit) {
    return myFridge.pop_elt(getit);
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





