#include "recipe.h"

Recipe::Recipe(std::string title) {
    this->title = title;
}

Recipe::~Recipe() {}

std::string Recipe::get_title() const {
    return title;
}

void Recipe::set_title(std::string title) {
    this->title = title;
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

void Recipe::set_ingredients(std::vector<std::string> ingredients) {
    this->ingredients = ingredients;
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

bool Recipe::operator==(const Recipe& other) const{
    return (title == other.get_title());
}

void Recipe::set_url(std::string url){
    this->url = url;
}

std::string Recipe::get_url(){
    return url;
}

double Recipe::get_time(){
    return time;
}

void Recipe::set_time(double time){
    this->time = time;
}
