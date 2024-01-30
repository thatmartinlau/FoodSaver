#include "../Header/profilemanager.h"
#include "../Header/currentUser.h"

ProfileManager::ProfileManager(QObject *parent) : QObject(parent) {}

void ProfileManager::clearFields() {
    // Logic to clear fields (handled in QML)
}

void ProfileManager::applyChanges(const QString &displayName, const QString &gender, const QString &address,
                                  const QString &promotion, const QString &phone, bool vegetarian,
                                  bool vegan, bool glutenFree, bool lactoseIntolerant, bool pescatarian, bool halal) {
    // Print out the information
    qDebug() << "Display Name:" << displayName;
    qDebug() << "Gender:" << gender;
    qDebug() << "Address:" << address;
    qDebug() << "Promotion:" << promotion;
    qDebug() << "Phone:" << phone;
    qDebug() << "Vegetarian:" << vegetarian;
    qDebug() << "Vegan:" << vegan;
    qDebug() << "Gluten Free:" << glutenFree;
    qDebug() << "Lactose Intolerant:" << lactoseIntolerant;
    qDebug() << "Pescatarian:" << pescatarian;
    qDebug() << "Halal:" << halal;

    std::string displayNamestr = displayName.toStdString(); // OK
    std::string genderstr = gender.toStdString();           // Convert to int
    std::string addressstr = address.toStdString();         // OK
    std::string promotionstr = promotion.toStdString();     // Convert to int
    std::string phonestr = phone.toStdString();             // Convert to int
    std::list<bool> food_restrictions = {vegetarian, vegan, glutenFree, lactoseIntolerant, pescatarian, halal};

    if (displayNamestr!="" && displayNamestr!=CurrentUser::currentUser.User::get_display_name()){
        CurrentUser::currentUser.User::set_display_name(displayNamestr);
    }
    qDebug() << "Name:" << CurrentUser::currentUser.User::get_display_name();

    if (genderstr!="" && genderstr!=CurrentUser::currentUser.User::get_display_name()){
        CurrentUser::currentUser.User::set_gender(genderstr);
    }
    if (addressstr!="" && addressstr!=CurrentUser::currentUser.User::get_room_number()){
        CurrentUser::currentUser.User::set_room_number(addressstr);
    }
    if (promotionstr!="" && promotionstr!=CurrentUser::currentUser.User::get_promotion()){
        CurrentUser::currentUser.User::set_promotion(promotionstr);
    }
    if (phonestr!="" && phonestr!=CurrentUser::currentUser.User::get_phone_number()){
        CurrentUser::currentUser.User::set_phone_number(phonestr);
    }
   //need to figure out food restrictions because diet is a tring in user class
}
