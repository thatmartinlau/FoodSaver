#ifndef RECIPE_H
#define RECIPE_H

#include<iostream>
#include <vector>
using namespace std;

class Recipe
{
public:
    Recipe(std::string title);
    ~Recipe();
    std::string get_title() const;
    void set_title(std::string title);
    std::vector<std::string> get_directions();
    void set_directions(std::vector<std::string> directions);
    std::vector<std::string> get_ingredients();
    void set_ingredients(std::vector<std::string> ingredients);
    std::string get_source();
    void set_source(std::string source);
    std::vector<std::string> get_tags();
    void set_tags(std::vector<std::string> tags);
    void add_tags(std::string tag);
    bool operator==(const Recipe& other) const;
    void set_url(std::string url);
    std::string get_url();
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
    double rating = 0;
    int times_rated = 0;

};

#endif // RECIPE_H
