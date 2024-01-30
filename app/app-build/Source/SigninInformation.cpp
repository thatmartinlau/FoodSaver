
#include "../Header/SigninInformation.h"
#include "../Header/user.h"
#include "../Header/currentUser.h"
#include <QDebug>
SigninInfo::SigninInfo(QObject *parent) : QObject(parent) {}

bool SigninInfo::setUserInfo(const QString &displayName, const QString &gender, const QString &address,
                             const QString &promotion, const QString &phone, const QString &telegram,
                             bool gluten, bool lactose, bool meat, bool halal_meat, bool fish,
                             bool nuts, bool eggs) {

    // check that the user input at least a name and a telegram username
    if (displayName.toStdString()=="" || telegram.toStdString()==""){
        emit openInfoError();
        return false;
    }

    else if (CurrentUser::currentUser.User::get_username() != "") {
        qDebug() << "Updating current user attributes:";

        // Update the attributes of the current user
        CurrentUser::currentUser.User::set_display_name(displayName.toStdString());
        qDebug() << "Display Name:" << QString::fromStdString(CurrentUser::currentUser.get_display_name());

        CurrentUser::currentUser.User::set_gender(gender.toStdString());
        qDebug() << "Gender:" << QString::fromStdString(CurrentUser::currentUser.User::get_gender());

        CurrentUser::currentUser.set_room_number(address.toStdString());
        qDebug() << "Room Number:" << QString::fromStdString(CurrentUser::currentUser.User::get_room_number());

        CurrentUser::currentUser.set_promotion(promotion.toStdString());
        qDebug() << "Promotion:" << QString::fromStdString(CurrentUser::currentUser.User::get_promotion());

        CurrentUser::currentUser.set_phone_number(phone.toStdString());
        qDebug() << "Phone Number:" << QString::fromStdString(CurrentUser::currentUser.User::get_phone_number());

        CurrentUser::currentUser.set_telegram(telegram.toStdString());
        qDebug() << "Telegram:" << QString::fromStdString(CurrentUser::currentUser.User::get_telegram());

        // Handle dietary restrictions

        // initialize to no dietary restrictions
        std::list<bool> diet = {true, true, true, true, true, true, true, true, true, true, true, true, true, true};

        // add more dietary restrictions
        if (!gluten) {
            auto gluten_i = diet.begin();; // gluten is at indice 1
            *gluten_i = false;
        } else if (!lactose) {
            auto lactose_i = std::next(diet.begin(), 4); //lactose is at indice 5
            *lactose_i = false;
        } else if (!meat) {
            auto meat_i = std::next(diet.begin(), 7); // meat is at indice 8
            *meat_i = false;
        } else if (!halal_meat) {
            auto halal_meat_i = std::prev(diet.end(),6);; // halal is at indice 9
            *halal_meat_i = false;
        } else if (!fish) {
            auto fish_i = std::prev(diet.end(),5); // fish is at indice 10
            *fish_i = false;
        }
        else if (!nuts) {
            auto nuts_i = std::prev(diet.end(),3); // nuts are at indice 12
            *nuts_i = false;
        }
        else if (!eggs) {
            auto eggs_i = std::next(diet.begin(), 6); // eggs are at indice 7
            *eggs_i = false;
        }


        emit openMarketPage();
        return true;

    } else {
        qDebug() << "Error: Current user is null.";
        emit openPreviousPage();
        return false;
    }
}
