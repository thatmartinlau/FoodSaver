#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QStringList>

class Backend : public QObject
{
    Q_OBJECT
public:
    explicit Backend(QObject *parent = nullptr);
    //virtual ~Backend();

    Q_INVOKABLE void generateRandomNumber();
    Q_INVOKABLE void storeName(const QString &name);
    Q_INVOKABLE QStringList getNameHistory() const;
    Q_INVOKABLE void openPopupWindow();

signals:
    void sumChanged(int newSum);
    void nameHistoryChanged();

private:
    int sum = 0;
    QStringList nameHistory;
};

#endif // BACKEND_H
