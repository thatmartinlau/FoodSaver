
#include "front.hpp"
#include <iostream>
#include <list>
#include "nlohmann/json.hpp"
using json = nlohmann::json;
using namespace std;




// For ingredients

json Ingredient::toJson() const {
    json ingredientJson;
    ingredientJson["name"] = *name;
    ingredientJson["quantity"] = *quantity;
    // Add serialization for other attributes if needed
    return ingredientJson;

}

// For Fridge

json Fridge::toJson() const {
    json fridgeJson;
    json ingredientsJsonArray;

    for (const Ingredient& ingredient : *ingredient_list) {
        ingredientsJsonArray.push_back(ingredient.toJson());
    }

    fridgeJson["ingredient_list"] = ingredientsJsonArray;
    return fridgeJson;
}

// For User :

json Offer:: toJson() const {
    json offerJson;
    offerJson["price"] = *price; // Assuming price is a pointer to double

    json ingredientsJsonArray;
    for (const Ingredient& ingredient : *ingredient_list) {
        ingredientsJsonArray.push_back(ingredient.toJson());
    }
    offerJson["ingredient_list"] = ingredientsJsonArray;

    return offerJson;
}
// For Offer


json User ::toJson() const {
    json userJson;
    userJson["username"] = *username;
    userJson["password"] = *password;
    // ... (Other attributes)
    return userJson;
}
