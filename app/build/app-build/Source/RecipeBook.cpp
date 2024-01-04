/*#include "Header/RecipeBook.h"
#include <iostream>
#include <list>
#include <vector>
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
    for (const auto& ingredient : jsonData["RecipeBook"][recipeIndex]["ingredients"]){
        ingredients.push_back(ingredient);
    }
    return ingredients;
}

std::vector<std::string> JsonRecipeReader::getRecipeTags(int recipeIndex) const{
    std::vector<std::string> recipetags;
    for (const auto& tag : jsonData["RecipeBook"][recipeIndex]["tags"]){
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

void JsonRecipeReader::addRecipeFromParameter(const std::string& title, const std::string>& description, const std::vector<std::string>& ingredients,const std::vector<std::string>& tags) {

    // convert the description into small strings based on sentence-ending punctuation marks.
    std::vector<std::string> description_sentences;
    size_t startPos = 0;

    for (size_t i = 0; i < input.length(); ++i) {
        char currentChar = input[i];

        // Check for sentence-ending punctuation marks
        if (currentChar == '.' || currentChar == '!' || currentChar == '?') {
            // Extract the sentence from startPos to the current position (including the punctuation mark)
            std::string sentence = input.substr(startPos, i - startPos + 1);

            // Trim leading and trailing whitespaces
            size_t firstNonSpace = sentence.find_first_not_of(" \t\n\r");
            size_t lastNonSpace = sentence.find_last_not_of(" \t\n\r");
            if (firstNonSpace != std::string::npos && lastNonSpace != std::string::npos) {
                sentence = sentence.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1);
            }

            // Add the sentence to the vector
            description_sentences.push_back(sentence);

            // Update the start position for the next sentence
            startPos = i + 1;
        }
    }

    // If there is a remaining part of the input, add it as the last sentence
    if (startPos < input.length()) {
        std::string lastSentence = input.substr(startPos);
        description_sentences.push_back(lastSentence);
    }

    // Create the Json new recipe file
    json newrecipe = {
        {"title", title},
        {"description", description_sentences},
        {"ingredients", ingredients}, // Question : How is the input ingredients ? One single string (as description) or directly vector of strings ?
        {"tags", tags}
    };

    addRecipe(newrecipe);
}*/



