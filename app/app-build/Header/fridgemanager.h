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

//private:
//    void parseDateString(const QString &dateString, int& day, int& month, int& year);

};
#endif // FRIDGEMANAGER_H
