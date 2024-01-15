#include "../Header/recipe.h"

Recipe::Recipe(std::string title) {
    this->title = title;
}

std::string Recipe::get_title() {
    return title;
}

void Recipe::set_title(std::string new_title) {
    this->title = new_title;
}

std::vector<std::string> Recipe::get_directions() {
    return directions;
}

void Recipe::set_directions(std::vector<std::string> directions) {
    this->directions = directions;
}

std::vector<std::string> Recipe::get_ingredients() {
    return ingredients;
}

void Recipe::set_ingredients(std::vector<std::string> new_ingredients) {
    this->ingredients = new_ingredients;
}

std::string Recipe::get_source() {
    return source;
}

void Recipe::set_source(std::string source) {
    this->source = source;
}

std::vector<std::string> Recipe::get_tags() {
    return tags;
}

void Recipe::set_tags(std::vector<std::string> tags) {
    this->tags = tags;
}

void Recipe::add_tags(std::string tag) {
    tags.push_back(tag);
}

void Recipe::set_diet(std::string dietary_restriction){
    this->dietary_restriction = dietary_restriction;
}

std::string Recipe::get_diet(){
    return dietary_restriction;
}

double Recipe::get_time(){
    return time;
}

void Recipe::set_time(double time){
    this->time = time;
}

void Recipe::add_ingredient(std::string ingredient_name){
    this->ingredients.push_back(ingredient_name);
}
