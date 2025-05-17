#ifndef DISH_H
#define DISH_H
#include <QString>

struct Dish
{
    QString name;
    int calories;
    int proteins;
    int fats;
    int carbohydrates;
    bool isValid()
    {
        return !name.isEmpty() && calories > 0;
    }
};

#endif // DISH_H
