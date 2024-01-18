#include "../Header/profilemanager.h"
#include "../Header/user.h"

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



    //Implement with currentuser classes
    /*
    currentuser.set

*/


    //figure out what to do with this information now
}
