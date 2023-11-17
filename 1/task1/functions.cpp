#include "functions.h"

void setTopThreelist(int (&a_topThreeList)[3], int &a_caloriesCarriedByElf){
    if(a_topThreeList[2] < a_caloriesCarriedByElf)
    {
        if(a_topThreeList[0] < a_caloriesCarriedByElf)
        {
            a_topThreeList[2] = a_topThreeList[1];
            a_topThreeList[1] = a_topThreeList[0];
            a_topThreeList[0] = a_caloriesCarriedByElf;
        }
        else if(a_topThreeList[1] < a_caloriesCarriedByElf)
        {
            a_topThreeList[2] = a_topThreeList[1];
            a_topThreeList[1] = a_caloriesCarriedByElf;
        }
        else if(a_topThreeList[2] < a_caloriesCarriedByElf)
        {
            a_topThreeList[2] = a_caloriesCarriedByElf;;
        }
    }
}
