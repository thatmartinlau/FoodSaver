
#include "../Header/SigninInformation.h"
#include "user.h"
#include "../Header/currentUser.h"
#include <QDebug>
SigninInfo::SigninInfo(QObject *parent) : QObject(parent) {}


int stripNonDigitsAndConvertToInt(const std::string& input) {
    std::string digitsOnly = input;
    digitsOnly.erase(
        std::remove_if(
            digitsOnly.begin(),
            digitsOnly.end(),
            [](unsigned char c) { return !std::isdigit(c); }
            ),
        digitsOnly.end()
        );

    // Convert the resulting string to an integer
    // Note: This will return 0 if the string is empty
    int result = 0;
    if (!digitsOnly.empty()) {
        result = std::stoi(digitsOnly);
    }

    return result;
}

void SigninInfo::setUserInfo(const QString &displayName, const QString &gender, const QString &address,
                             const QString &promotion, const QString &phone, bool vegetarian,
                             bool vegan, bool glutenFree, bool lactoseIntolerant, bool pescatarian, bool halal) {

    if (CurrentUser::currentUser.User::get_username() != "") {
        qDebug() << "Updating current user attributes:";

        // Update the attributes of the current user
        CurrentUser::currentUser.User::set_display_name(displayName.toStdString());
        qDebug() << "Display Name:" << QString::fromStdString(CurrentUser::currentUser.get_display_name());

        std::string genderstr = gender.toStdString();
        int gender_signin;
        if (genderstr == "Male") {
            gender_signin = 0;
        }
        else if (genderstr == "Female") {
            gender_signin = 1;
        }
        else if (genderstr == "Prefer not to say") {
            gender_signin = 2;
        }

        CurrentUser::currentUser.User::set_gender(gender_signin);
        qDebug() << "Gender:" << QString::fromStdString(std::to_string(CurrentUser::currentUser.User::get_gender()));

        CurrentUser::currentUser.set_room_number(address.toStdString());
        qDebug() << "Room Number:" << QString::fromStdString(CurrentUser::currentUser.User::get_room_number());

        std::string promotionstr = promotion.toStdString();
        int promotionBX;
        if (promotionstr == "BX2025") {
            promotionBX = 2025;
        }
        else if (promotionstr == "BX2026") {
            promotionBX = 2026;
        }
        else {promotionBX = 2024;}

        CurrentUser::currentUser.set_promotion(promotionBX);
        qDebug() << "Promotion:" << QString::fromStdString(std::to_string(CurrentUser::currentUser.User::get_promotion()));

        std::string phonestr = phone.toStdString();
        int phoneint = stripNonDigitsAndConvertToInt(phonestr);

        CurrentUser::currentUser.set_phone_number(phoneint);
        qDebug() << "Phone Number:" << QString::fromStdString(std::to_string(CurrentUser::currentUser.User::get_phone_number()));

        // Handle dietary restrictions
        std::vector diet = {0,0,0,0,0,0};
        if (vegan) {
            diet[0] = 1;
        } else if (glutenFree) {
            diet[1] = 1;
        } else if (vegetarian) {
            diet[2] = 1;
        } else if (pescatarian) {
            diet[3] = 1;
        } else if (halal) {
            diet[4] = 1;
        }
        else if (lactoseIntolerant) {
            diet[5] = 1;
        }

        std::list<bool> boolList;

        // Transform vector into list of bools
        for (int value : diet) {
            boolList.push_back(static_cast<bool>(value));
        }

        if (!diet.empty()) {
            CurrentUser::currentUser.set_food_and_dietary_restrictions(boolList);
            //qDebug() << "Diet:" << QString::fromStdString(CurrentUser::currentUser.User::get_food_and_dietary_restrictions());
        }

        qDebug() << "Update complete.";
        emit openMarketPage();
    } else {
        qDebug() << "Error: Current user is null.";
        emit openPreviousPage();
    }
}
