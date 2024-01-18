#ifndef RECIPE_H
#define RECIPE_H

#include<iostream>

class Recipe
{
public:
    Recipe(std::string title);
    ~Recipe(){};
    std::string get_title();
    void set_title(std::string title);
    std::vector<std::string> get_directions();
    void set_directions(std::vector<std::string> directions);
    std::vector<std::string> get_ingredients();
    void set_ingredients(std::vector<std::string> ingredients);
    void add_ingredient(std::string ingredient_name);
    std::string get_source();
    void set_source(std::string source);
    std::vector<std::string> get_tags();
    void set_tags(std::vector<std::string> tags);
    void add_tags(std::string tag);
    void set_diet(std::string dietary_restriction);
    std::string get_diet();
    void set_time(double time);
    double get_time();

private:
    std::string title;
    double time;
    std::vector<std::string> directions;
    std::vector<std::string> ingredients;
    std::string dietary_restriction;
    std::string source;
    std::vector<std::string> tags;
    std::string url;


};

#endif // RECIPE_H
