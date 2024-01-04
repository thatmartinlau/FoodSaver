#ifndef RECIPEBOOK_HPP
#define RECIPEBOOK_HPP
// Front end class definitions
#include <iostream>
#include <list>
#include <string>
#include <ctime>
#include <vector>
#include <regex>
#include <json/json.h>
#include <fstream>
#include "nlohmann/json.hpp"
#include "restClient.cpp"
using json = nlohmann::json;
using namespace std;

/////////////////////////////////////////////////////////////////////////////////
// Class JsonRecipeReader : access and read the elements of the recipe given the
// Json file with all the recipes.


class JsonRecipeReader{
public :
    JsonRecipeReader(const std::string& filename) : jsonFileName(filename) {
        loadJson();
    }

    std::string getRecipeTitle(int recipeIndex)const{}
    std::vector<std::string> getRecipeIngredients(int recipeIndex) const{}
    std::vector<std::string> getRecipeDirection(int recipeIndex) const{}
    std::vector<std::string> getRecipeTags(int recipeIndex) const{}
    std::string getRecipeUrl(int recipeIndex) const{}
    void addRecipe(const json newRecipe) {}
    void addRecipeFromParameter(const std::string& title, const std::string>& description, const std::vector<std::string>& ingredients,const std::vector<std::string>& tags) {}

private:
    void loadJson() {
        std::ifstream file(jsonFileName);
        if (!file.is_open()){
            std::cerr << "Error opening file: "<< jsonFileName<< std::endl;
            return ;
        }
        file >> jsonData;
        file.close();
    }

    void saveJson() const {
        std::ifstream file(jsonFileName);
        if (!file.open()){
            std::cerr << "Error opening the file: " << jsonFileName << std::endl;
            return ;
        }
        file << jsonData.dump(2);
        file.close();
    }
    std::string jsonFileName;
    json jsonData ;
};

#endif // RECIPEBOOK_HPP
