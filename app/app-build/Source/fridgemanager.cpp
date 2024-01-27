#include "../Header/fridgemanager.h"
#include "../Header/date.h"

#include <iostream>
#include <sstream>
#include <QDebug>
#include <iostream>
#include <list>


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

/*QString convertDateToQString(const Date& date) {
    return QString("%1/%2/%3").arg(date.get_day(), 2, 10, QLatin1Char('0'))
        .arg(date.get_month(), 2, 10, QLatin1Char('0'))
        .arg(date.get_year());
}*/

Fridge myFridge;
FridgeManager::FridgeManager(QObject *parent) : QObject(parent) {}

void FridgeManager::add_elt(const QString &name, const QString &date, const QString &quantity, const QString &cat) {

    //those two lines
    qDebug() << "Display Name:" << name;
    qDebug() << "Category:" << cat;

    std::string dateString = date.toStdString();
    int parsedDay = std::stoi(dateString.substr(0, 2));
    int parsedMonth = std::stoi(dateString.substr(3, 2));
    int parsedYear = std::stoi(dateString.substr(6, 4));

    //this line
    std::cout << "Date:" << parsedDay << parsedMonth << parsedYear << std::endl;

    std::string nameitem = name.toStdString();
    int quantityitem = quantity.toInt();
    //std::string catitem = cat.toStdString();
    Food_class catitem = convertStringToFoodClass(cat.toStdString());

    //Fridge myFridge;
    myFridge.add_elt(Ingredient(nameitem, Date(parsedDay, parsedMonth, parsedYear), quantityitem, catitem));

    std::cout << "Added an element to the fridge!" << std::endl;
}
Ingredient FridgeManager::pop_elt(Ingredient *getit) {
    //Fridge myFridge;
    return myFridge.pop_elt(getit);
}


std::vector<Ingredient> FridgeManager::sort_ingredients_by_category() {
    //Fridge myFridge;
    return myFridge.sort_ingredients_by_category();
}

#include <QList>

QList<QList<QString>> FridgeManager::sort_ingredients_by_expiration_date() {
    std::vector<Ingredient> sortedIngredients = myFridge.sort_ingredients_by_expiration_date();

    QList<QList<QString>> result;

    for (Ingredient& ingredient : sortedIngredients) {
        QList<QString> ingredientInfo;
        ingredientInfo.append(convertStdtoQ2(ingredient.get_name()));         // Name
        ingredientInfo.append(convertStdtoQ2(ingredient.get_expiry_date().Date::formateDate())); // Date using convertDateToQString()
        ingredientInfo.append(convertStdtoQ2(std::to_string(ingredient.get_quantity()))); // Quantity
        ingredientInfo.append(convertStdtoQ2(ingredient.get_food_class_name())); // Category
        //ingredientInfo.append(convertStdtoQ2("unspecified")); // Category

        result.append(ingredientInfo);
    }
    return result;
}




