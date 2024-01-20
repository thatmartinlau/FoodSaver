// maincontroller.cpp
#include "maincontroller.h"
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
    //res.fromStdString(entry);
    return res;
}

    MainController::MainController(QObject *parent) : QObject(parent)
{
}

QString MainController::submitText(const QString &text)
{
    if (!text.trimmed().isEmpty()) {
        qDebug() << "User has typed:" << text;
        return text;
    }
}


double changeTime(const QString &hours, const QString &minutes)
{
    //QStringList list1 = text.split(u'h');
    //if (!list1[0].trimmed().isEmpty() && !list1[1].trimmed().isEmpty()) {
    //qDebug() << "User has typed time:" << text;
    QString copyHrs = hours;
    QString copyMin = minutes;
    int res[2] = {copyHrs.toInt(), copyMin.toInt()};

    double decimal = (double)res[1]/(double)60;
    double time = (double)res[0] + decimal;
    return time;
    //}
}

int MainController::submitInt(const int &time)
{
    qDebug() << "time is:" << time;
    return time + 20;
}

std::vector<Recipe> allRecipes;
std::vector<std::string> test;
std::vector<std::string> allInstructions;
QList<QString> rated_recipes;

void MainController::submitTitleForRating(const QString &title){
    rated_recipes.append(title);
}

double tester=1.64;

QString MainController::submitRating(const QString &user_rating){
    double usr_rating = user_rating.toDouble();
    double res;
    for(int i = 0; i<allRecipes.size();i++){
        if(convertStdtoQ(allRecipes[i].get_title()).toLower() == rated_recipes[0].toLower()){
            allRecipes[i].add_rating(usr_rating);
            res = allRecipes[i].get_rating();
        }
    }
    rated_recipes.clear();
    tester = user_rating.toDouble();
    return QString::number(res);
}

QString MainController::getRating(const QString &title){
    //double res;

    for(int i = 0; i<allRecipes.size();i++){
        if(convertStdtoQ(allRecipes[i].get_title()).toLower() == title.toLower()){
            //allRecipes[i].add_rating(usr_rating);
            return QString::number(allRecipes[i].get_rating());
        }
    }
    return "ERR";

    //return res
    //return QString::number(res);
}

void MainController::submitAll(const QString &recipeName, const QString &diet, const QString &hours, const QString &minutes)//, const QString &ingredient1, const QString &instruction1)
{
    std::vector<std::string> vecttt;

    std::string name = convertQtoStd(recipeName);
    Recipe new_recipe(name);
    std::cout << "EHHHH"<< new_recipe.get_ingredients().size() <<std::endl;
    std::cout << vecttt.size() << std::endl;
    std::cout << "HELLO" << std::endl;

    std::string diet_restr = convertQtoStd(diet);
    new_recipe.set_diet(diet_restr);
    new_recipe.set_time(changeTime(hours,minutes));
    std::cout << vecttt.size() << std::endl;
    vecttt.push_back(diet_restr);
    std::cout << vecttt.size() << std::endl;
    std::cout << "HELLO" << std::endl;
    std::cout << "EHHHH"<< new_recipe.get_ingredients().size() <<std::endl;

    new_recipe.set_ingredients(test);
    std::string scd = "secondingr";
    //new_recipe.add_ingredient(scd);
    std::cout << "EHHHH"<< new_recipe.get_ingredients().size() <<std::endl;
    new_recipe.set_directions(allInstructions);
    allRecipes.push_back(new_recipe);

    //qDebug() << "name" << recipeName << "diet" << diet<< "ingr" << ingredient1<< "instr" << instruction1 << "hours"<< hours << "minutes" << minutes;
    //return changeTime(hours, minutes);
    //return convertStdtoQ(new_recipe.get_title());
}



QString MainController::submitIngredients(const QString &ingredientName){
    /*Recipe temp_recipe = allRecipes[0];

    std::string title ="heymoon";
    temp_recipe.set_title(title);
    temp_recipe.add_ingredient(convertQtoStd(ingredientName));
    std::cout << "OHMAGAAWWWD"<< temp_recipe.get_ingredients().size() <<std::endl;
    std::string str = "boy aah";
    test.push_back(convertQtoStd(ingredientName));
    //temp_recipe.set_title();
    //title = "actually";
    temp_recipe.set_ingredients(temp_recipe.get_ingredients());
    return convertStdtoQ(temp_recipe.get_title());*/
    test.push_back(convertQtoStd(ingredientName));
    return ingredientName;
}

void MainController::submitInstructions(const QString &instruction){
    allInstructions.push_back(convertQtoStd(instruction));
}

QString MainController::get_ingr(){
    std::cout << "hello2";

    if(allRecipes[0].get_directions().empty()){
        std::cout << "hello";
        QString res = convertStdtoQ(allRecipes[0].get_title());
        return res;

    }else{
        QString res = convertStdtoQ(allRecipes[0].get_directions()[allRecipes[0].get_directions().size()-1]);
        //QString res = convertStdtoQ(allRecipes[0].get_ingredients()[0]);
        return res;
    }
    //std::string test = "hello";
    //QString res = QString::fromStdString(test);
    //res.fromStdString(test);
    //return res;
}

QList<QString> list_names;
//QString dummy = "Dummy";
//list_recipies.append(dummy);

void MainController::submit(const QString &recipeName)
{
    qDebug() << "name"; //<< recipeName << "diet" << diet<< "ingr" << ingredient1<< "instr" << instruction1 << "hours"<< hours << "minutes" << minutes;
    std::cout << "RESULT";
    if(!list_names.contains(recipeName)){
        std::string str = "lol";
        Recipe test(str);
        list_names.append(recipeName);
    }
}

QString MainController::gett(const int &i)
{
    //qDebug() << "name" << recipeName << "diet" << diet<< "ingr" << ingredient1<< "instr" << instruction1 << "hours"<< hours << "minutes" << minutes;
    //QList<QString>::iterator r = list_recipies.begin();
    //QString temp = list_recipies.at(i);
    //list_recipies.pop_front();
    return list_names.at(i);
}

int MainController::getTotalLength(){
    return list_names.size();
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////*/
//Search Bar

/*QList<QString> MainController::search(const QString &entry){
    QList<QString> res;
    res.append("test1");
    res.append("test2");
    return res;
}*/

//QList<QString> list_names = list_recipies;
QMap<QString, int> dict;
QList<QString> tagsLasagna;

QList<QString> construct_lstnames(QList<QString> lstnames){
    lstnames.clear();
    for(int i = 0; i < allRecipes.size();i++){
        lstnames.append(convertStdtoQ(allRecipes[i].get_title()));
        //for(int j=0; j < allRecipes[i].get_ingredients().size(); j++){
        //    lstnames.append(convertStdtoQ(allRecipes[i].get_ingredients()[j]));
        //}
    }
    return lstnames;
}

QList<QString> construct_templst(int i){
    //tmplst.clear();
    QList<QString> tmplst = list_names[i].split(u' ', Qt::SkipEmptyParts);
    for(int j=0; j < allRecipes[i].get_ingredients().size(); j++){
        tmplst.append(convertStdtoQ(allRecipes[i].get_ingredients()[j]));
    }
    return tmplst;
}

QList<QString> MainController::search_res(const QString &entry){
    //std::cout << "Search was: " << entry.toStdString() ;
    //qDebug() << "Hello";
    tagsLasagna.append("pasta");
    tagsLasagna.append("heavy");
    tagsLasagna.append("carrot");
    tagsLasagna.append("celery");
    tagsLasagna.append("yummy");

    list_names=construct_lstnames(list_names);


    for(int i = 0; i<list_names.size(); i++){
        dict[list_names[i]] = 0;
    }

    QList<QString> list_entry = entry.split(u' ', Qt::SkipEmptyParts);
    for(int i = 0; i<list_entry.size(); i++){
        for(int j = 0; j<list_names.size(); j++){
            //dict[list_names[j]] = 0;

            QList<QString> temp_list = construct_templst(j);//list_names[j].split(u' ', Qt::SkipEmptyParts);

            for(int h = 0; h<temp_list.size(); h++){
                temp_list[h] = temp_list[h].toLower();
            }
            if(temp_list.contains(list_entry[i].toLower())){
                dict[list_names[j]]++;

                //for(int h=0; h<allRecipes.)

                //qDebug() << "FOUND" << list_entry[i] << " and " << temp_list.size() ;
                //return "found: " + list_entry[i];
            }


            //qDebug() << "temporary" << list_names[j]<< " btw " <<dict[list_names[j]] << " data_bs " << list_names.size() ;

        }
    }

    //qDebug() << "LOOP DONE";

    QList<QString> res = sorter(dict);

    //QString s = QString::number(dict["Vegetarian Lasagna"]);
    QList<QString> final;
    final.clear();


    //qDebug() << "sizes: " << res.size() << " and " << list_names.size();

    for(int i = 0; i< res.size(); i++){
        if(dict[res[i]] != 0){
            final.append(res[i]);
            //final = final + "Name: " + res[i] + " Occurences: " + QString::number(dict[res[i]]);
        }

    }

    if(final.isEmpty()){
        final.append("NOTHING FOUND");
    }
    //QList<QString> copy_final =final;

    return final;
}

QList<QString> MainController::titleOrDiet(const QList<QString> &titles,const int &need){
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



QList<QString> MainController::sorter(const QMap<QString, int> &dict){
    QList<int> occurences = dict.values();
    QList<QString> names = dict.keys();

    //qDebug() << "sizesSORT: " << occurences.size() << " and " << list_names.size() << " and " << names.size();


    //for(auto r = copy.cbegin(); r!= copy.cend(); r++){
    //    qDebug() << copy[r];
    //}

    for(int i = 0; i<10*occurences.size(); i++){
        for(int j = 0; j<occurences.size()-1; j++){
            if (occurences[j] < occurences[j+1]){
                occurences.swapItemsAt(j,j+1);
                names.swapItemsAt(j,j+1);
            }
        }
    }
    //qDebug() << occurences << occurences[1] << occurences[2];
    return names;
}
std::string filename = "Recipes.json";
JsonRecipeReader reader(filename);
//json jsonData1 = readJsonFromFile("Recipies.json");

QString MainController::getJsonRTitle(const int &h){
    std::string title; // = reader.getRecipeTitle(h);
    QString res = "lol";
    title = "bonjour";//jsonData1["RecipeBook"][h]["title"];
    res = res.fromStdString(title);
    return res;
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
