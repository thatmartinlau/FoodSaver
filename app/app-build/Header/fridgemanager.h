#ifndef FRIDGEMANAGER_H
#define FRIDGEMANAGER_H

#include <QObject>
#include <QString>
#include <QDebug>

#include "ingredient.h"
#include "fridge.h"



class FridgeManager : public QObject {
    Q_OBJECT

public:
    explicit FridgeManager(QObject *parent = nullptr);

public slots:
    void add_elt(const QString &name, const QString &date, const QString &quantity, const QString &cat);
    Ingredient pop_elt(const QString &nb);
    std::vector<Ingredient> sort_ingredients_by_category();
    QList<QList<QString>> sort_ingredients_by_expiration_date();
    QList<QList<QList<QString>>> search_result(const QString &request);

    //std::string convertQtoStd(QString entry);
    //QString convertStdtoQ(std::string entry);
    //QString convertDateToQString(const Date& date);
//private:
//    void parseDateString(const QString &dateString, int& day, int& month, int& year);

};
#endif // FRIDGEMANAGER_H
