
#include "../Header/SigninInformation.h"
#include "../Header/user.h"
#include "../Header/currentUser.h"
#include <QDebug>
SigninInfo::SigninInfo(QObject *parent) : QObject(parent) {}

bool SigninInfo::setUserInfo(const QString &displayName, const QString &telegram, const QString &gender, const QString &address,
                             const QString &promotion, const QString &phone, bool vegetarian,
                             bool vegan, bool glutenFree, bool lactoseIntolerant, bool pescatarian, bool halal) {

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

        // Initialize user's dietary restrictions
        std::string diet = "";
        if (vegan) {
            diet = "vegan";
        } else if (glutenFree) {
            diet = "glutenFree";
        } else if (vegetarian) {
            diet = "vegetarian";
        } else if (pescatarian) {
            diet = "pescatarian";
        } else if (halal) {
            diet = "halal";
        }
        else if (lactoseIntolerant) {
            diet = "lactoseIntolerant";
        }

        if (!diet.empty()) {
            CurrentUser::currentUser.set_diet(diet);
            qDebug() << "Diet:" << QString::fromStdString(CurrentUser::currentUser.User::get_diet());
        }
        emit openMarketPage();
        return true;

    } else {
        qDebug() << "Error: Current user is null.";
        emit openPreviousPage();
        return false;
    }
}
