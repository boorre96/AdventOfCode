#include "calorielist.h"

CalorieList::CalorieList() : m_mostCalories{}, m_topThreeList{0,0,0}, m_caloriesCarriedByElf{}
{

}

void CalorieList::setTopThreeList(int a_caloriesCarriedByElf)
{
    if(m_topThreeList[2] < a_caloriesCarriedByElf)
    {
        if(m_topThreeList[0] < a_caloriesCarriedByElf)
        {
            m_topThreeList[2] = m_topThreeList[1];
            m_topThreeList[1] = m_topThreeList[0];
            m_topThreeList[0] = a_caloriesCarriedByElf;
            setMostCalories(a_caloriesCarriedByElf);
        }
        else if(m_topThreeList[1] < a_caloriesCarriedByElf)
        {
            m_topThreeList[2] = m_topThreeList[1];
            m_topThreeList[1] = a_caloriesCarriedByElf;
        }
        else if(m_topThreeList[2] < a_caloriesCarriedByElf)
        {
            m_topThreeList[2] = a_caloriesCarriedByElf;;
        }
    }


}

int CalorieList::getMostCalories() const
{
    return m_mostCalories;
}

void CalorieList::setMostCalories(int const newMostCalories)
{
    m_mostCalories = newMostCalories;
}

int CalorieList::getSumOfTopThreeList()
{
    int sumOfCal = 0;
    for(int i = 0; i < 3; ++i)
    {
        sumOfCal += m_topThreeList[i];
    }
    return sumOfCal;
}
