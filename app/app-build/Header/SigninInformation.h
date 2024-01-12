#ifndef SIGNININFORMATION_H
#define SIGNININFORMATION_H
#include <QObject>
#include <QString>

class SigninInfo : public QObject {
    Q_OBJECT
public:
    explicit SigninInfo(QObject *parent = nullptr);

    Q_INVOKABLE bool signInInfo();

public slots:
    void clearFields();
    void setUserInfo(const QString &displayName, const QString &gender, const QString &address,
                      const QString &promotion, const QString &phone, bool vegetarian,
                      bool vegan, bool glutenFree, bool lactoseIntolerant, bool pescatarian, bool halal);
};
#endif // SIGNININFORMATION_H
