#pragma once

class calorieList
{
public:
    calorieList();
    void setTopThreeList(int a_caloriesCarriedByElf);

    int getMostCalories() const;
    void setMostCalories(int newMostCalories);

    int getSumOfTopThreeList();

private:
    int m_mostCalories{};
    int m_topThreeList[3];
    int m_caloriesCarriedByElf{};
};
