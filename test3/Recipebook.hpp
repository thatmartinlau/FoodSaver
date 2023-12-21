#ifndef FRONT_HPP
#define FRONT_HPP
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
using json = nlohmann::json;

using namespace std;
class RecipeParser{
public :
    RecipeParser(const std::string& url, const std::string& pageEncoding = ENCODING);
    void setsource();
    void setLanguage();
    void setFilename();
    Json::Value compose();
    void save(const std::string& folder = OUTPUT_FOLDER);
    void store(const std::string& database, const std::string& collection, const std::map<std::string, std::string>& mongoService = ARMS)
    virtual std::string getTitle();
    virtual std::string getImage();
    virtual std::vector<std::string> getIngredients();
    virtual std::vector<sts::string> getDirections();
    virtual std::vector<std::string> getTags();
    virtual qstd::vector<std::string> getOtherRecipeLinks();

private:
    std::string url;
    std::string encoding;
    std::string html;
    bool valid;
    std::string encode;
    std::string source;
    std::string language;
    std::string filename;
    Json::Value json;
}; 

class Epicurious : public RecipeParse{
public:
    Epicurious();
    ~Epicurious();
    std::string getTitle();
    std::string getImage();
    std::vector<std::string> getIngredients();
    std::vector<std::string> getDirections();
    std::vector<std::string> getTags();
    std::vector<std::string> getOtherRecipeLink();
private:
    regex badTag;
};

#endif // RECIPEBOOK_HPP
