#include "personalcookbookcontroller.h"
#include "Source/user.cpp"
#include <QDebug>
#include <iostream>
#include <list>
#include <string>


std::string convertQtoStd(QString entry){
    std::string res;
    res = entry.toStdString();
    return res;
}

QString convertStdtoQ(std::string entry){
    QString res = QString::fromStdString(entry);
    return res;
}

PersonalCookbookController::PersonalCookbookController(QObject *parent) : QObject(parent)
{
}

void PersonalCookbookController::likeRecipe(const QString &recipeName)
{
    // Check if the recipe is not already liked
    if (!likedRecipes.contains(recipeName)) {
        likedRecipes.append(recipeName);
        // Add your logic to update backend or perform any other necessary actions
    }
}

void PersonalCookbookController::unlikeRecipe(const QString &recipeName)
{
    // Check if the recipe is liked
    int index = likedRecipes.indexOf(recipeName);
    if (index != -1) {
        likedRecipes.removeAt(index);
        // Add your logic to update backend or perform any other necessary actions
    }
}

QList<QString> PersonalCookbookController::getLikedRecipes()
{
    return likedRecipes;
}
