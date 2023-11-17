#ifndef ELVES_H
#define ELVES_H

#include "caloriegenerator.h"


class Elves
{
public:
    Elves(CalorieGenerator &calorieGenerator);


    int getElfWithMostCalories() const;
    void setElfWithMostCalories(int newElfWithMostCalories);

    CalorieGenerator &calorieGenerator() const;

    ifstream& getList();


private:
    CalorieGenerator& m_calorieGenerator;
    int m_elfWithMostCalories;
    int m_topThreeList[3];
};

#endif // ELVES_H
