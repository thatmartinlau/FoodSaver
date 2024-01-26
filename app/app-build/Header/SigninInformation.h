#ifndef SIGNININFORMATION_H
#define SIGNININFORMATION_H
#include <QObject>
#include <QString>

class SigninInfo : public QObject {
    Q_OBJECT
public:
    explicit SigninInfo(QObject *parent = nullptr);


public slots:
    void setUserInfo(const QString &displayName, const QString &gender, const QString &address,
                      const QString &promotion, const QString &phone, bool vegetarian,
                      bool vegan, bool glutenFree, bool lactoseIntolerant, bool pescatarian, bool halal);


signals:
void openMarketPage();
void openPreviousPage();

};
#endif // SIGNININFORMATION_H
