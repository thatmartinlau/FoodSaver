#ifndef PERSONALCOOKBOOKCONTROLLER_H
#define PERSONALCOOKBOOKCONTROLLER_H

#include <QObject>
#include <QString>
#include <QList>

class PersonalCookbookController : public QObject
{
    Q_OBJECT

public:
    explicit PersonalCookbookController(QObject *parent = nullptr);

public slots:
    void likeRecipe(const QString &recipeName);
    void unlikeRecipe(const QString &recipeName);
    QList<QString> getLikedRecipes();

private:
    QList<QString> likedRecipes;
};

#endif // PERSONALCOOKBOOKCONTROLLER_H
