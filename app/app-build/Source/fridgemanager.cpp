#include "../Header/fridgemanager.h"
#include "../Header/date.h"

#include <iostream>
#include <sstream>

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
    std::string catitem = cat.toStdString();

    //Fridge myFridge;
    myFridge.add_elt(Ingredient(nameitem, Date(parsedDay, parsedMonth, parsedYear), quantityitem));

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
std::vector<Ingredient> FridgeManager::sort_ingredients_by_expiration_date() {
    //Fridge myFridge;
    return myFridge.sort_ingredients_by_expiration_date();
}
