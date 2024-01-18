#include "../Header/settingsmanager.h"
#include "../Header/user.h"

#include <QDebug>

SettingsManager::SettingsManager(QObject *parent) : QObject(parent) {
    // Constructor implementation (if needed)
}

QString SettingsManager::changePassword(const QString &newPassword, const QString &confirmPassword) {
    if (newPassword == confirmPassword) {
        qDebug() << "Password changed to:" << newPassword;
        return "Password successfully changed.";
    } else {
        return "Passwords do not match.";
    }
}

QString SettingsManager::bindTelegramUsername(const QString &username) {
    qDebug() << "Telegram username:" << username;
    return username;
}

QString SettingsManager::processNotifications(bool switchTop, bool switchBottom) {
    QString result;
    result += switchTop ? "1" : "0";
    result += switchBottom ? "1" : "0";
    qDebug() << "Notification settings:" << result;
    return result;
}
