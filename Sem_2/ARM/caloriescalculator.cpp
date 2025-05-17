#include "caloriescalculator.h"
#include <QDebug>

int CaloriesCalculator::calculateBRM(const UserPreference &p) const
{
    if(p.gender == UserPreference::MALE) return (10 * p.weight) + (6.25 * p.height) - (5 * p.age) + 5;
    else return (10 * p.weight) + (6.25 * p.height) - (5 * p.age) - 161;
}

int CaloriesCalculator::calculateTDEE(const UserPreference &p) const // умножаем на коэф. тренировочной активности
{
    qDebug() << calculateBRM(p) << ' ' << getTrainingCoef(p);
    return calculateBRM(p) * getTrainingCoef(p);
}

int CaloriesCalculator::calculateSurplus(const UserPreference &p) const // расчет профицита
{
    int BRM = calculateBRM(p);
    if(p.goal == UserPreference::LOSS)
        return -BRM * DEFICIT_PERCENTAGE;
    else
        return BRM * getProficitPercentage(p);
}

int CaloriesCalculator::calculateTargetCalories(const UserPreference &p)
{
    return calculateTDEE(p) + calculateSurplus(p);
}

double CaloriesCalculator::getProficitPercentage(const UserPreference &p) const
{
    if(p.training < 1) return 0.20;
    if(p.training < 2) return 0.15;
    if(p.training < 5) return 0.10;
    return 0.05;
}

double CaloriesCalculator::getTrainingCoef(const UserPreference &p) const
{
    switch(p.trainingActivity)
    {
    case UserPreference::SEDENTARY:
        return 1.2;
        break;
    case UserPreference::EASY:
        return 1.375;
        break;
    case UserPreference::MODERATE:
        return 1.55;
        break;
    case UserPreference::INTENSE:
        return 1.7;
        break;
    case UserPreference::EXTREME:
        return 1.9;
        break;
    default:
        return 1.375;
    }
}
/*
Сидячий =1,2 — минимальная активность, сидячая работа без значительных физических нагрузок;

Легкий = 1,375 — низкий уровень уровень активности: вы иногда занимаетесь скандинавской ходьбой, катаетесь на велосипеде, время от времени играете в дворовый волейбол, любите поплавать, когда есть возможность, но не каждый день. Этот же коэффициент могут выбрать те, кто каждый день много ходит;

Умеренный = 1,55 — умеренный уровень активности: вы интенсивно тренируетесь 30-60 минут три-четыре раза в неделю;

Интенсивный = 1,7 — интенсивный уровень активности. Такой коэффициент могут вставить в формулу те, кто активно занимается спортом 5-7 дней в неделю, он же подходит для тех, кто занят тяжелым физическим трудом: строительством, дорожными и сельскохозяйственными работами;

Экстремальный = 1,9 — экстремальный уровень: очень энергозатратные виды деятельности (занятия спортом с несколькими тренировками каждый день), физически затратная работа — например, сгребание угля или уборка снега.
*/
