#include <iostream>
#include <vector>
#include "caloriegenerator.h"
#include "calorielist.h"

using namespace std;
std::string c_nameOfFile = "C:/Users/boris/OneDrive/Documents/Projects/adventOFCode/1/task1/inputFile.txt";

int main()
{

    CalorieGenerator Elves(c_nameOfFile);
    calorieList list;

    while(Elves.getElfKaloriList().is_open()){
        int caloriesCarriedByElf = Elves.getCalorieLineFromFile();
        if(caloriesCarriedByElf == Error::NOMORECALORIES)
            break;
        else
            list.setTopThreeList(caloriesCarriedByElf);
    }
    cout << " The most calories carried by an Elf was: " << list.getMostCalories() << endl;
    cout << " Sum of the top three elves: "<< list.getSumOfTopThreeList() << endl;

}
