#pragma once
#include <fstream>
#include <string>

using namespace std;

enum Error{
    NOMORECALORIES = -1
};

class CalorieGenerator
{
public:
    CalorieGenerator(string &txtFilename);

    ifstream& getElfKaloriList();
    int getCalorieLineFromFile();
    int calculateTotalCalories(string &caloriesPicked);


private:
    ifstream m_elfKaloriList;
    string m_nrOfCalElf;
    string m_eachCalStored;
    int m_kalories;


};
