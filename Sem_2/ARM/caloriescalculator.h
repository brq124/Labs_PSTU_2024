#ifndef CALORIESCALCULATOR_H
#define CALORIESCALCULATOR_H
#include "UserPreference.h"

class CaloriesCalculator
{
public:
    int calculateBRM(const UserPreference &p) const; // Формула Миффлина-Сан Жеора
    int calculateTDEE(const UserPreference &p) const; // умножаем на коэф. тренировочной активности
    int calculateSurplus(const UserPreference &p) const; // расчет профицита / дефицита
    int calculateTargetCalories(const UserPreference &p); // расчет итогового колва калорий
private:
    static constexpr double DEFICIT_PERCENTAGE = 0.15;
    double getProficitPercentage(const UserPreference &p) const;
    double getTrainingCoef(const UserPreference &p) const;
};

#endif // CALORIESCALCULATOR_H
