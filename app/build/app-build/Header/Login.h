#ifndef LOGIN_H
#define LOGIN_H

#include <QObject>
#include <QString>

class Login : public QObject {
    Q_OBJECT

public:
    explicit Login(QObject *parent = nullptr);

public slots:
    bool checkCredentials(const QString &username, const QString &password);
};

#endif // LOGIN_H
