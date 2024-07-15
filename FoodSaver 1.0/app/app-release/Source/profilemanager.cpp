#include "../Header/profilemanager.h"
#include "../Header/currentUser.h"

ProfileManager::ProfileManager(QObject *parent) : QObject(parent) {}

void ProfileManager::clearFields() {
    // Logic to clear fields (handled in QML)
}

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
    int gender_profile;
    if (genderstr == "Male") {
        gender_profile = 0;
    }
    else if (genderstr == "Female") {
        gender_profile = 1;
    }
    else if (genderstr == "Prefer not to say") {
        gender_profile = 2;
    }

    std::string addressstr = address.toStdString();         // OK
    std::string promotionstr = promotion.toStdString();     // Convert to int
    int promotionBX;
    if (promotionstr == "BX2025") {
        promotionBX = 2025;
    }
    else if (promotionstr == "BX2026") {
        promotionBX = 2026;
    }
    else {promotionBX = 2024;}
    std::string phonestr = phone.toStdString();             // Convert to int
    int phoneint = stripNonDigitsAndConvertToInt(phonestr);

    std::list<bool> food_restrictions = {vegetarian, vegan, glutenFree, lactoseIntolerant, pescatarian, halal};


    CurrentUser::currentUser.User::set_display_name(displayNamestr);
    CurrentUser::currentUser.User::set_gender(gender_profile);
    CurrentUser::currentUser.User::set_room_number(addressstr);
    CurrentUser::currentUser.User::set_promotion(promotionBX);
    CurrentUser::currentUser.User::set_phone_number(phoneint);
    //CurrentUser::currentUser.User::set_diet(phonestr);




    //figure out what to do with this information now
}
