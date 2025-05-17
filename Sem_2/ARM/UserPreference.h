#ifndef USERPREFERENCE_H
#define USERPREFERENCE_H

struct UserPreference
{
    enum Gender
    {
        MALE,
        FEMALE
    } gender;
    int age;
    int weight;
    int height;
    int training;
    enum TrainingActivity
    {
        SEDENTARY,
        EASY,
        MODERATE,
        INTENSE,
        EXTREME
    } trainingActivity;
    enum Goal
    {
        LOSS,
        GAIN
    } goal;
};

#endif // USERPREFERENCE_H
