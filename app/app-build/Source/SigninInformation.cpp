
#include "../Header/SigninInformation.h"
#include "../Header/user.h"
#include "../Header/currentUser.h"
SigninInfo::SigninInfo(QObject *parent) : QObject(parent) {}

void SigninInfo::setUserInfo(const QString &displayName, const QString &gender, const QString &address,
                             const QString &promotion, const QString &phone, bool vegetarian,
                             bool vegan, bool glutenFree, bool lactoseIntolerant, bool pescatarian, bool halal) {

    // extern User user = currentUser;
    // std::string displayNamestr = displayName.toStdString();
    // currentUser.set_display_name(displayNamestr);

    std::string genderstr = gender.toStdString();
    // User::set_gender(genderstr);

    std::string addressstr = address.toStdString();
    // User::set_room_number(addressstr);

    std::string promotionstr = promotion.toStdString();
    // User::set_promotion(promotionstr);

    std::string phonestr = phone.toStdString();
    // User::set_phone_number(phonestr);
    emit openFridge();

    // if (vegan){
    //     std::string diet="vegan";
    //     User::set_diet(diet);
    // }
    // else if (glutenFree){
    //     std::string diet="glutenFree";
    //     User::set_diet(diet);
    // }
    // else if (vegetarian){
    //     std::string diet="vegetarian";
    //     User::set_diet(diet);
    // }
    // else if (pescatarian){
    //     std::string diet="pescatarian";
    //     User::set_diet(diet);
    // }
    // else if (halal){
    //     std::string diet="halal";
    //     User::set_diet(diet);
    // }
}


