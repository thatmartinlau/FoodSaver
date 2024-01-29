#ifndef PROFILEMANAGER_H
#define PROFILEMANAGER_H

#include <QObject>
#include <QString>
#include <QDebug>

class ProfileManager : public QObject {
    Q_OBJECT

public:
    explicit ProfileManager(QObject *parent = nullptr);

public slots:
    void clearFields();
    void applyChanges(const QString &displayName, const QString &gender, const QString &address,
                      const QString &promotion, const QString &phone, bool vegetarian,
                      bool vegan, bool glutenFree, bool lactoseIntolerant, bool pescatarian, bool halal);
};

#endif // PROFILEMANAGER_H
