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
// RECIPEPARSER
RecipeParser::RecipeParser(const std::string& url, const std::string& pageEncoding = ENCODING)
        : url(url), encoding(pageEncoding), valid(false) {
        html = restClient.get(url, encoding);
        if (!html.empty()) {
            valid = true;
            encode = pageEncoding;
            Json::CharReaderBuilder reader;
            Json::Value json;
            std::istringstream jsonStream(html);
            Json::parseFromStream(reader, jsonStream, &json, nullptr);
            this->json = json;
        } else {
            throw std::invalid_argument("Could not fetch data from: \"" + url + "\"");
        }
  }

void RecipeParser::setSource() {
  source = urlsplit(url).netloc;
}

void RecipeParser::setLanguage() {
    language = "en-US";
}

void RecipeParser::setFilename() {
    filename = urlsplit(url).path;
    size_t lastSlash = filename.find_last_of('/');
    if (lastSlash != std::string::npos) {
        filename = filename.substr(lastSlash + 1);
    }
    size_t lastDot = filename.find_last_of('.');
    if (lastDot != std::string::npos) {
        filename = filename.substr(0, lastDot);
    }
    filename += ".json";
}

Json::Value RecipeParser::compose() {
    setSource();
    setLanguage();
    return {
        {"source", source},
        {"language", language},
        {"title", getTitle()},
        {"image", getImage()},
        {"ingredients", getIngredients()},
        {"directions", getDirections()},
        {"tags", getTags()},
        {"url", url}
    };
}

void RecipeParser::save(const std::string& folder = OUTPUT_FOLDER) {
    Json::StreamWriterBuilder writer;
    std::string data = Json::writeString(writer, compose());

    if (!valid) {
        std::cerr << "[error] invalid data at: " << url << std::endl;
    } else {
        setFilename();
        try {
            std::ofstream file(os::path::join(folder, filename));
            file << data;
            file.close();
        } catch (const std::exception& e) {
            std::cerr << "[error] could not write recipe json in: " << os::path::join(folder, filename) << std::endl;
        }
    }
}

void RecipeParser::store(const std::string& database, const std::string& collection, const std::map<std::string, std::string>& mongoService = ARMS) {
    if (mongoService.size() != 3 || std::any_of(mongoService.begin(), mongoService.end(), [](const auto& kv) { return kv.second.empty(); })) {
        std::cerr << "[error] mongo service not fully defined" << std::endl;
    } else {
        Json::StreamWriterBuilder writer;
        std::string data = Json::writeString(writer, compose());

        if (!valid) {
            std::cerr << "[error] invalid data at: " << url << std::endl;
        } else {
            std::map<std::string, std::string> headers = {
                {"API-KEY", mongoService.at("API-KEY")},
                {"API-TOTP", totpGenerator.create(mongoService.at("API-SEED"))}
            };

            std::string target = mongoService.at("SERVER") + "/" + database + "/" + collection;
            int result = restClient.put(target, data, encoding, headers);

            if (result < 200 || result >= 205) {
                std::cerr << "[error] could not PUT " << url << " to " << target << ": " << result << std::endl;
            }
        }
    }
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// EPICURIOUS 

Epicurious::Epicurious() : badTag("Bon App\u00e9tit", std::regex_constants::icase) {}

std::string Epicurious::getTitle(){
    // The title format is: <title>[Recipe] recipe | Epicurious.com</title>
    // We want just 'Recipe'
    std::string title = getTree().xpath("//title")[0].text();
    size_t pipePos = title.find('|');
    title = title.substr(0, pipePos);
    size_t lastSpacePos = title.find_last_of(' ');
    title = title.substr(0, lastSpacePos);
    return title;
}

std::string Epicurious::getImage() {
    // The image format is: <meta property="og:image" content="IMG_URL">
    // We want just 'IMG_URL'
    return getTree().xpath("//meta[@property='og:image']")[0].get("content");
}

std::vector<std::string> Epicurious::getIngredients() {
    // Return a list or a map of the recipe ingredients
    std::vector<std::string> data;
    for (auto node : getTree().xpath("//li[@itemprop='ingredients']")) {
        std::string ingredient = "";
        for (auto textNode : node.xpath("descendant-or-self::text()")) {
            ingredient += textNode;
        }
        data.push_back(ingredient);
    }
    return data;
}

std::vector<std::string> Epicurious::getDirections() {
    // Return a list or a map of the preparation instructions
    std::vector<std::string> data;
    for (auto node : getTree().xpath("//li[@class='preparation-step']")) {
        std::string direction = "";
        for (auto textNode : node.xpath("descendant-or-self::text()")) {
            direction += textNode;
        }
        data.push_back(direction);
    }
    return data;
}

std::vector<std::string> Epicurious::getTags() {
    // Return a list of tags for this recipe
    std::vector<std::string> data;
    for (auto node : getTree().xpath("//*[@itemprop='recipeCategory']")) {
        std::string tag = "";
        for (auto textNode : node.xpath("descendant-or-self::text()")) {
            tag += textNode;
        }
        data.push_back(tag);
    }
    
    // Filter out tags containing 'Bon Appétit'
    auto filterFunc = [this](const std::string& x) { return std::regex_search(x, this->badTag) == false; };
    data.erase(std::remove_if(data.begin(), data.end(), filterFunc), data.end());
    
    return data;
}

std::vector<std::string> Epicurious::getOtherRecipeLinks() {
    // Return a list of other recipes found on the page
    std::vector<std::string> data;
    for (auto link : getTree().xpath("//div[contains(@class,'recipes')]/ul[contains(@class,'content')]/*/a")) {
        if (link.has_attribute("href")) {
            std::string l = "http://www.epicurious.com" + link.get_attribute("href");
            if (std::find(data.begin(), data.end(), l) == data.end()) {
                data.push_back(l);
            }
        }
    }
    return data;
}
