#include "elves.h"

Elves::Elves(CalorieGenerator &a_calorieGenerator) : m_calorieGenerator(a_calorieGenerator), m_elfWithMostCalories{}, m_topThreeList{0,0,0}
{

}

int Elves::getElfWithMostCalories() const
{
    return m_elfWithMostCalories;
}

void Elves::setElfWithMostCalories(int a_newElfWithMostCalories)
{
    m_elfWithMostCalories = a_newElfWithMostCalories;
}

CalorieGenerator &Elves::calorieGenerator() const
{
    return m_calorieGenerator;
}

ifstream& Elves::getList()
{

    return calorieGenerator().getElfKaloriList();

}
