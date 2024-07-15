// maincontroller.cpp
#include "recipecontroller.h"
#include "Source/recipe.cpp"
#include <QDebug>
#include <iostream>
#include <list>
#include "Source/RecipeBook.cpp"
//modif eli
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
//
// modif Charlotte
#include <sstream>
#include <string>
#include <fstream>

/*#include "Source/temp.json.cpp"
#include "Header/RecipeBook.h"
#include <vector>
#include "Header/front.hpp"
#include "nlohmann/json.hpp"
using Json = nlohmann::json;
//using namespace std;*/

std::string convertQtoStd(QString entry){
    std::string res;
    res = entry.toStdString();
    return res;
}

QString convertStdtoQ(std::string entry){
    QString res = QString::fromStdString(entry);
    return res;
}

    RecipeController::RecipeController(QObject *parent) : QObject(parent)
{
}

QString RecipeController::submitText(const QString &text)
{
    if (!text.trimmed().isEmpty()) {
        qDebug() << "User has typed:" << text;
        return text;
    }
}


double changeTime(const QString &hours, const QString &minutes) //converts two time strings to a single double (for example: 1h , 30min --> 1.5 hrs)
{
    QString copyHrs = hours;
    QString copyMin = minutes;
    int res[2] = {copyHrs.toInt(), copyMin.toInt()};

    double decimal = (double)res[1]/(double)60;
    double time = (double)res[0] + decimal;
    return time;
}

int RecipeController::submitInt(const int &time) //testing purposes
{
    qDebug() << "time is:" << time;
    return time + 20;
}

std::vector<Recipe> allRecipes;
std::vector<std::string> test;
std::vector<std::string> allInstructions;
std::vector<std::string> allIngredients;
QList<QString> rated_recipes;

void temp_allRecipes_extension(std::vector<Recipe> book){
    for(int i = 0; i<book.size(); i++){
        allRecipes.push_back(book[i]);
    }
}

// -------------- This secction deals with the visualisation of the recipes by the users (it sends/recieves all that needs to be displayed)


QList< QList<QString> > vis_titles;

QList<QString> RecipeController::sendTitleForVis(const QString &title){
    //std::cout << "MAN why" << std::endl;
    QList<QString> res;
    for(int i = 0; i<allRecipes.size();i++){
        if(title == convertStdtoQ(allRecipes[i].get_title())){
            res.append(title);
            res.append(convertStdtoQ(allRecipes[i].get_diet()));

            res.append(QString::number(allRecipes[i].get_time()));
        }
    }
    vis_titles.append(res);
    //std::cout << vis_titles.isEmpty() << std::endl;
    //std::cout << convertQtoStd(vis_titles[0][0]) << std::endl;

    return res;
}

QList<QString> RecipeController::sendIngredientsForVis(const QString &title){
    QList<QString> res;
    res.clear();
    //std::cout<< convertQtoStd(title) << std::endl;
    for(int i = 0; i<allRecipes.size();i++){
        if(title == convertStdtoQ(allRecipes[i].get_title())){
            //std::cout << i << "    ----" << std::endl;
            std::vector<std::string> ingrs = allRecipes[i].get_ingredients();
            for(int j = 0; j<ingrs.size();j++){
                //std::cout << "ingrdients: ---- " << ingrs[j] << std::endl;
                res.append(convertStdtoQ(ingrs[j]));
            }
        }
    }
    vis_titles.append(res);
    //std::cout << "just checking_ingr"<< convertQtoStd(res[res.size()-1]) << std::endl;
    //std::cout << res.size() << std::endl;
    return res;
}

QList<QString> RecipeController::sendInstructionsForVis(const QString &title){
    QList<QString> res;
    for(int i = 0; i<allRecipes.size();i++){
        if(title == convertStdtoQ(allRecipes[i].get_title())){
            std::vector<std::string> instr = allRecipes[i].get_directions();
            for(int j = 0; j<instr.size();j++){
                res.append(convertStdtoQ(instr[j]));
            }
        }
    }
    vis_titles.append(res);
    //std::cout << "just checking" << std::endl;
    //std::cout << convertQtoStd( res[0]) << std::endl;
    return res;
}

QString RecipeController::sendRatingForVis(const QString &title){
    QString res;
    for(int i = 0; i<allRecipes.size();i++){
        if(title == convertStdtoQ(allRecipes[i].get_title())){
            res = QString::number(allRecipes[i].get_rating());
        }
    }
    return res;
}


QList<QString> RecipeController::getTitleForVis(){
    QList<QString> test;
    test.append("one");
    test.append("two");
    //std::cout << "vis_titles.isEmpty()" << std::endl;
    //std::cout << vis_titles.isEmpty() << std::endl;
    if(vis_titles.isEmpty() == true){
        QList<QString> lol;
        lol.append("bob");
        return lol;
    }else{
        return vis_titles[0];
    }
}



QList<QString> RecipeController::getIngredientsForVis(){
    return vis_titles[1];
}

QList<QString> RecipeController::getInstructionsForVis(){
    QList<QString> temp;
    return temp;
}


// -------------- This section deals with the rating of the recipes

void RecipeController::submitTitleForRating(const QString &title){
    rated_recipes.append(title);
}

double tester=1.64;

QString RecipeController::submitRating(const QString &user_rating){
    double usr_rating = user_rating.toDouble();
    double res;
    for(int i = 0; i<allRecipes.size();i++){
        if(convertStdtoQ(allRecipes[i].get_title()).toLower() == rated_recipes[0].toLower()){
            //std::cout<< 222220 << usr_rating<<std::endl;
            allRecipes[i].add_rating(usr_rating);
            res = allRecipes[i].get_rating();
            //std::cout<< 3333330 << res<<std::endl;
        }
    }
    rated_recipes.clear();
    tester = user_rating.toDouble();
    //std::cout<< 11111111110 << res << std::endl;
    return QString::number(res);
}

QString RecipeController::getRating(const QString &title){

    for(int i = 0; i<allRecipes.size();i++){
        if(convertStdtoQ(allRecipes[i].get_title()).toLower() == title.toLower()){
            return QString::number(allRecipes[i].get_rating());
        }
    }
    return "ERR";
}


// -------------- This section deals with the creation of a new recipe - creating a recipe object from what the user wrote in the UI

void RecipeController::submitAll(const QString &recipeName, const QString &diet, const QString &hours, const QString &minutes)//, const QString &ingredient1, const QString &instruction1)
{
    std::vector<std::string> vecttt;

    std::string name = convertQtoStd(recipeName);
    Recipe new_recipe(name);
    //std::cout << vecttt.size() << std::endl;

    std::string diet_restr = convertQtoStd(diet);
    new_recipe.set_diet(diet_restr);
    new_recipe.set_time(changeTime(hours,minutes));
    //std::cout << vecttt.size() << std::endl;
    vecttt.push_back(diet_restr);
    //std::cout << vecttt.size() << std::endl;

    new_recipe.set_ingredients(allIngredients);
    std::string scd = "secondingr";
    new_recipe.set_directions(allInstructions);
    allInstructions.clear();
    allIngredients.clear();
    allRecipes.push_back(new_recipe);
}



QString RecipeController::submitIngredients(const QString &ingredientName){
    allIngredients.push_back(convertQtoStd(ingredientName));
    test.push_back(convertQtoStd(ingredientName));
    return ingredientName;
}

void RecipeController::submitInstructions(const QString &instruction){
    allInstructions.push_back(convertQtoStd(instruction));
}

QString RecipeController::get_ingr(){
    //std::cout << "hello2";

    if(allRecipes[0].get_directions().empty()){
        //std::cout << "hello";
        QString res = convertStdtoQ(allRecipes[0].get_title());
        return res;

    }else{
        QString res = convertStdtoQ(allRecipes[0].get_directions()[allRecipes[0].get_directions().size()-1]);
        return res;
    }
}

QList<QString> list_names;


// -------------- This section deals with the visualisation of the recipes in the main window, as small boxes with only titles and ratings

void RecipeController::submit(const QString &recipeName)
{
    qDebug() << "name"; //<< recipeName << "diet" << diet<< "ingr" << ingredient1<< "instr" << instruction1 << "hours"<< hours << "minutes" << minutes;
    //std::cout << "RESULT";
    if(!list_names.contains(recipeName)){
        std::string str = "lol";
        Recipe test(str);
        list_names.append(recipeName);
    }
}

QString RecipeController::gett(const int &i)
{
    return list_names.at(i);
}

int RecipeController::getTotalLength(){
    return list_names.size();
}

bool RecipeController::checkTitle(const QString &title){
    for(int i = 0; i<allRecipes.size();i++){
        if(convertStdtoQ(allRecipes[i].get_title()) == title){
            return false;
        }
    }
    return true;
}

// -------------- This section deals with the search bar

QMap<QString, int> dict;
QList<QString> tagsLasagna;

QList<QString> construct_lstnames(QList<QString> lstnames){
    lstnames.clear();
    for(int i = 0; i < allRecipes.size();i++){
        lstnames.append(convertStdtoQ(allRecipes[i].get_title()));
    }
    return lstnames;
}

QList<QString> construct_templst(int i){
    QList<QString> tmplst = list_names[i].split(u' ', Qt::SkipEmptyParts);
    for(int j=0; j < allRecipes[i].get_ingredients().size(); j++){
        QList<QString> ingrs_split = convertStdtoQ(allRecipes[i].get_ingredients()[j]).split(" ");
        for(int h = 0; h<ingrs_split.size(); h ++){
            tmplst.append(ingrs_split[h]);
        }
    }
    tmplst.append(convertStdtoQ(allRecipes[i].get_diet()));
    return tmplst;
}

QList<QString> RecipeController::search_res(const QString &entry){

    list_names=construct_lstnames(list_names);
    //std::cout << list_names.size() << std::endl;


    for(int i = 0; i<list_names.size(); i++){
        dict[list_names[i]] = 0;
    }

    QList<QString> list_entry = entry.split(u' ', Qt::SkipEmptyParts);
    for(int i = 0; i<list_entry.size(); i++){
        for(int j = 0; j<list_names.size(); j++){

            QList<QString> temp_list = construct_templst(j);//list_names[j].split(u' ', Qt::SkipEmptyParts);

            for(int h = 0; h<temp_list.size(); h++){
                temp_list[h] = temp_list[h].toLower();
            }
            if(temp_list.contains(list_entry[i].toLower())){
                dict[list_names[j]]++;

            }
        }
    }
    QList<QString> res = sorter(dict);

    QList<QString> final;
    final.clear();

    for(int i = 0; i< res.size(); i++){
        if(dict[res[i]] != 0){
            final.append(res[i]);
        }
    }

    if(final.isEmpty()){
        final.append("NOTHING FOUND");
    }

    return final;
}

QList<QString> RecipeController::titleOrDiet(const QList<QString> &titles,const int &need){
    QList<QString> res;
    for(int i = 0; i<titles.size();i++){
        for(int j = 0; j<allRecipes.size(); j++){
            if(need == 0){
                if(convertStdtoQ(allRecipes[j].get_title()).toLower() == titles[i].toLower()){
                    res.append(convertStdtoQ(allRecipes[j].get_title()));
                }
            }else{
                if(convertStdtoQ(allRecipes[j].get_title()).toLower() == titles[i].toLower()){
                    res.append(convertStdtoQ(allRecipes[j].get_diet()));
                }
            }
        }
    }
    return res;
}



QList<QString> RecipeController::sorter(const QMap<QString, int> &dict){
    QList<int> occurences = dict.values();
    QList<QString> names = dict.keys();


    for(int i = 0; i<10*occurences.size(); i++){
        for(int j = 0; j<occurences.size()-1; j++){
            if (occurences[j] < occurences[j+1]){
                occurences.swapItemsAt(j,j+1);
                names.swapItemsAt(j,j+1);
            }
        }
    }
    return names;
}


//modif eli:
/*the function no longer returns recipes from listnames but rather iterates through the Recipes.json seen previously and iterates over the titles of
the recipes or the tags. for optimal return, there should be assigned a score to each recipe for each ingredient they have in common with the output,
and be sorted even higher if the dietary restriction is the same.*/
/*QList<QString> MainController::searchRecipes(const QString &entry, const QString &dietRestriction) {
    QList<QString> result;

    // Load and parse the Recipes.json file
    QFile file("Recipes.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open Recipes.json";
        return result;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    QJsonObject recipesObject = doc.object();
    QJsonArray recipeArray = recipesObject["RecipeBook"].toArray();

    // Initialize a QMap to store recipe scores
    QMap<QString, int> recipeScores;

    // Split the search entry into a list of words
    //QList<QString> searchWords = entry.split(QRegExp("\\W+"), Qt::SkipEmptyParts);
    QList<QString> searchWords = entry.split(u' ', Qt::SkipEmptyParts);

    // Iterate through each recipe in the dataset
    for (int i = 0; i < recipeArray.size(); ++i) {
        QJsonObject recipe = recipeArray[i].toObject();
        QString title = recipe["title"].toString();
        QStringList tags = recipe["tags"].toStringList();

        // Initialize score for the current recipe
        int score = 0;

        // Check common ingredients and update the score
        QStringList ingredients = recipe["ingredients"].toStringList();
        for (const QString &ingredient : ingredients) {
            if (searchWords.contains(ingredient, Qt::CaseInsensitive)) {
                // Found a common ingredient
                score += 1;
            }
        }

        // Check dietary restriction and update the score
        QString recipeDiet = tags.contains(dietRestriction, Qt::CaseInsensitive) ? dietRestriction : "";
        if (!recipeDiet.isEmpty()) {
            score += 2;  // Higher score for matching dietary restriction
        }

        // Assign the score to the recipe in the QMap
        recipeScores[title] = score;
    }

    // Sort the recipes based on scores in descending order
    QList<QString> sortedRecipes = sorter(recipeScores);

    // Add the sorted recipes to the result list
    for (const QString &recipe : sortedRecipes) {
        result.append(recipe);
    }

    // Return the final result
    return result;
}*/

// -------------- This section links the textfile full of recipes to the UI

std::vector<std::string> splitpoint(const std::string& s, const char& delim){

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

std::vector<Recipe> originalsrecipe() {


    //ifstream file;
    //std::string array[MAX_LINE];

    //file.open("jsonformatter.txt");

    //// Open the text file
    std::ifstream file("jsonformatter.txt");

    if (file.fail()) {
        std::cout << "Error opening the file." << std::endl;
        std::vector<Recipe> empty;
        return empty;
    }else{
        std::cout << "hi" <<std::endl;
    }

    std::string line;
    std::vector<Recipe> book;


    int lines_count(0);
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string title, direction, extracomma, ingredients, source, tags, url;


        std::getline(ss, title, '"'); // directions, ingredients, source, tags, url;
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
        //recipe.set_url(url);
        recipe.set_time(00);

        book.push_back(recipe);

        lines_count ++;
    }

    return book;
}


void RecipeController::initial(){
    temp_allRecipes_extension(originalsrecipe());
}


