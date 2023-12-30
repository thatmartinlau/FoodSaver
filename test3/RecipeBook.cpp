#include "RecipeBook.hpp"
#include <iostream>
#include <list>
#include <ctime>
#include <vector>
#include <regex>
#include <chrono>
#include "front.hpp"
#include "nlohmann/json.hpp"
using Json = nlohmann::json;
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////
// JSON RECIPE READER 

std::string JsonRecipeReader::getRecipeTitle(int recipeIndex) const{
    return jsonData["RecipeBook"][recipeIndex]["title"];
}

std::vector<std::string> JsonRecipeReader::getRecipeDirections(int recipeIndex) const{
    std::vector<std::string> directions;
    for (const auto& direction : jsonData["RecipeBook"][recipeIndex]["direction"]){
        directions.push_back(direction);
    }
    return directions;
}

std::vector<std::string> JsonRecipeReader::getRecipeIngredients(int recipeIndex) const{
    std::vector<std::string> ingredients;
    for (const auto& ingredient : jsonData["RecipeBook"][recipeIndex]["Ingredients"]){
        ingredients.push_back(ingredient);
    }
    return ingredients;
}

std::vector<std::string> JsonRecipeReader::getRecipeTags(int recipeIndex) const{
    std::vector<std::string> recipetags;
    for (const auto& tag : jsonData["RecipeBook"][recipeIndex]["Tags"]){
        recipetags.push_back(tag);
    }
    return recipetags;
}

std::string JsonRecipeReader::getRecipeUrl(int recipeIndex) const {
        return jsonData["RecipeBook"][recipeIndex]["url"];
}

void JsonRecipeReader::addRecipe(const json& newRecipe) {
        jsonData["RecipeBook"].push_back(newRecipe);
        saveJson();
}
        
