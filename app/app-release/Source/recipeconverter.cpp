#include "recipe.h"
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <fstream>
#include <sstream>

// Use to split the string according to one specific delimiter.
std::vector<std::string> splitpoint2(const std::string& s, const char& delim){

    std::vector<std::string> result;
    std::string sentence;
    std::stringstream ss(s);

    while (getline(ss, sentence, delim))
    {
        if (sentence[0]==',' or sentence[0]==')' or sentence[0]==' '){
            sentence.erase(0,1);
        }
        result.push_back(sentence);
    }

    return result;
}

/*// Return the vector of recipes = recipe book
std::vector<Recipe> originalsrecipe() {

    // Open the text file "originalsrecipes'.txt"
    std::ifstream file("originalsrecipes.txt");

    if (file.fail()) {
        std::cout << "Error opening the file." << std::endl;
        std::vector<Recipe> empty;
        return empty;
    }else{
        std::cout << "The file is open !" <<std::endl;
    }

    std::string line;
    std::vector<Recipe> book;


    int lines_count(0);
    while (std::getline(file, line)) {
        std::stringstream ss(line);

        // directions, ingredients, source, tags, url;
        std::string title, direction, extracomma, ingredients, source, tags, url;


        std::getline(ss, title, '"');
        std::getline(ss, direction, '"');
        std::getline(ss, extracomma, '"');
        std::getline(ss, ingredients , '"');
        std::getline(ss, source, '"');
        std::getline(ss, tags, '"');
        std::getline(ss, url);


        title.pop_back(); // remove the ','
        source.pop_back();
        source.erase(0,1);
        url.erase(0,1);

        Recipe recipe(title);

        recipe.set_directions(splitpoint(direction,'.'));
        recipe.set_ingredients(splitpoint(ingredients, ','));
        recipe.set_source(source);
        recipe.set_tags(splitpoint(tags, ','));
        recipe.set_url(url);
        recipe.set_time(00);

        book.push_back(recipe);

        lines_count ++;
    }

    return book;
}*/

// Use to merge string into one single string
std::string concatenatestring(std::vector<std::string> vector){
    std::string result;
    for (auto string:vector){
        result += " " + string ;
    }
    return result;
}

// Use to merge string into one single string using a specific structure for directions of the recipe
std::string concatenatedirection(std::vector<std::string> vector){
    std::string result;
    for (auto string:vector){
        result += " " + string + ".";
    }
    return result;
}

// Use to merge string into one single string a specific structure for tags of the recipe
std::string concatenatetags(std::vector<std::string> vector){
    std::string result;
    for (auto string:vector){
        result += " ," + string ;
    }
    return result;
}

// Convert the vector of Recipes into a vector of strings
std::vector<std::string> vec_recipe_to_string(std::vector<Recipe> recipes) {
    std::vector<std::string> result;

    for (auto recipe:recipes){

        // create the full string corresponding to one recipe.
        std::string fullstring;

        // concatenate all the element into one string.
        fullstring = recipe.get_title() + " @" + concatenatedirection(recipe.get_directions()) + " %" + concatenatestring(recipe.get_ingredients()) + " *" + recipe.get_source() + " #"+ concatenatetags(recipe.get_tags()).erase(0,2) + "," + recipe.get_url();
        result.push_back(fullstring);
    }
    return result;
}

// Convert a vector of strings into a vector of Recipes
std::vector<Recipe> vec_string_to_recipe(std::vector<std::string> recipes){

    std::vector<Recipe> result;

    recipes.erase(recipes.begin());

    for (auto recipe : recipes){

        // get the title
        std::vector<std::string> title;
        title = splitpoint2(recipe, '@');

        Recipe recette(title[0]);

        // string recipes is of the form : "title @ directions % ingredients * source # tags , url
        std::vector<std::string> directions = splitpoint2(title[1], '%');
        std::vector<std::string> ingredients = splitpoint2(directions[1], '*');
        std::vector<std::string> source = splitpoint2(ingredients[1], '#');
        std::vector<std::string> tags = splitpoint2(source[1], ',');
        std::string url = tags.back();
        tags.pop_back();


        // fill the informations according to the recipe
        recette.set_directions(splitpoint2(directions[0], '.'));
        recette.set_ingredients(splitpoint2(ingredients[0], ','));
        recette.set_source(source[0]);
        recette.set_tags(tags);
        recette.set_url(url);
        recette.set_time(00);

        // add to the vector
        result.push_back(recette);
    }
    return result;
}
