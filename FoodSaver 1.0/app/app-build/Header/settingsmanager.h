#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <QObject>
#include <QString>

class SettingsManager : public QObject {
    Q_OBJECT
public:
    explicit SettingsManager(QObject *parent = nullptr);

public slots:
    QString changePassword(const QString &newPassword, const QString &confirmPassword);
    QString bindTelegramUsername(const QString &username);
    QString processNotifications(bool switchTop, bool switchBottom);
};

#endif // SETTINGSMANAGER_H
