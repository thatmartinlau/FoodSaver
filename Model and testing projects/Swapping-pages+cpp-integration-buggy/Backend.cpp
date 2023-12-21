#include "Backend.h"
#include <QRandomGenerator>
#include <QQmlApplicationEngine>
#include <QQmlComponent>

Backend::Backend(QObject *parent) : QObject(parent) {}

void Backend::generateRandomNumber() {
    int randomNumber = QRandomGenerator::global()->bounded(100);
    sum += randomNumber;
    emit sumChanged(sum);
}

void Backend::storeName(const QString &name) {
    nameHistory.append(name);
    emit nameHistoryChanged();
}

QStringList Backend::getNameHistory() const {
    return nameHistory;
}

void Backend::openPopupWindow() {
    QQmlApplicationEngine engine;
    QQmlComponent component(&engine, QUrl(QStringLiteral("qrc:/PopupWindow.qml")));
    QObject *popup = component.create();
    Q_UNUSED(popup)
}
