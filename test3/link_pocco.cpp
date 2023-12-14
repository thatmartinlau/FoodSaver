
#include "front.hpp"
#include <iostream>
#include <list>
//#include <nlohmann/json.hpp>
//using json = nlohmann::json;
using namespace std;




// For ingredients
/*
json toJson() {
    json ingredientJson;
    ingredientJson["name"] = *name;
    ingredientJson["quantity"] = *quantity;
    ingredientJson["category"] = category->toJson();
    ingredientJson["expiry_date"] = *expiry_date;
    ingredientJson["priority_level"] = static_cast<int>(priority_level);

    return ingredientJson;
}


// For Fridge
json toJson() {
    json fridgeJson;
    json ingredientsJsonArray;

    for (const Ingredient& ingredient : *ingredient_list) {
        ingredientsJsonArray.push_back(ingredient.toJson());
    }

    fridgeJson["ingredient_list"] = ingredientsJsonArray;

    return fridgeJson;
}


// For User :

json User :: intoJson(){
    json Json_dic;
    Json_dic ["username"] = *username;
    userJson["password"] = *password;
    userJson["telegram_username"] = *telegram_username;
    userJson ["user_fridge"] = user_fridge ->toJson();
    return Json_dic ;

}
*/




