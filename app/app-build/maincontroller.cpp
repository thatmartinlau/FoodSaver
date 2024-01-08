// maincontroller.cpp
#include "maincontroller.h"
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

/*#include "Source/temp.json.cpp"
#include "Header/RecipeBook.h"
#include <vector>
#include "Header/front.hpp"
#include "nlohmann/json.hpp"
using Json = nlohmann::json;
//using namespace std;*/

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

double MainController::changeTime(const QString &text)
{
    QStringList list1 = text.split(u'h');
    if (!list1[0].trimmed().isEmpty() && !list1[1].trimmed().isEmpty()) {
        qDebug() << "User has typed time:" << text;
        QString copyHrs = list1[0];
        QString copyMin = list1[1];
        int res[2] = {copyHrs.toInt(), copyMin.toInt()};

        double decimal = (double)res[1]/(double)60;
        double time = (double)res[0] + decimal;
        return time;
    }
}

int MainController::submitInt(const int &time)
{
    qDebug() << "time is:" << time;
    return time + 20;
}

QString MainController::submitAll(const QString &recipeName, const QString &diet, const QString &hours, const QString &minutes, const QString &ingredient1, const QString &instruction1)
{
    //qDebug() << "name" << recipeName << "diet" << diet<< "ingr" << ingredient1<< "instr" << instruction1 << "hours"<< hours << "minutes" << minutes;
    return recipeName+diet+hours+minutes+ingredient1+instruction1;
}

QList<QString> list_names;
//QString dummy = "Dummy";
//list_recipies.append(dummy);

void MainController::submit(const QString &recipeName)
{
    qDebug() << "name"; //<< recipeName << "diet" << diet<< "ingr" << ingredient1<< "instr" << instruction1 << "hours"<< hours << "minutes" << minutes;
    std::cout << "RESULT";
    if(!list_names.contains(recipeName)){
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

QList<QString> MainController::search_res(const QString &entry){
    //std::cout << "Search was: " << entry.toStdString() ;
    //qDebug() << "Hello";

    for(int i = 0; i<list_names.size(); i++){
        dict[list_names[i]] = 0;
    }

    QList<QString> list_entry = entry.split(u' ', Qt::SkipEmptyParts);
    for(int i = 0; i<list_entry.size(); i++){
        for(int j = 0; j<list_names.size(); j++){
            //dict[list_names[j]] = 0;
            QList<QString> temp_list = list_names[j].split(u' ', Qt::SkipEmptyParts);

            for(int h = 0; h<temp_list.size(); h++){
                temp_list[h] = temp_list[h].toLower();
            }
            if(temp_list.contains(list_entry[i].toLower())){
                dict[list_names[j]]++;

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
