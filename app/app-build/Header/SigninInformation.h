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
                      const QString &promotion, const QString &phone, const QString &telegram,
                     bool gluten, bool lactose, bool meat, bool halal_meat, bool fish, bool nuts,
                     bool eggs);


signals:
void openMarketPage();
void openPreviousPage();
void openNameAndTelegramError();
void closeNameAndTelegramError();
};
#endif // SIGNININFORMATION_H
