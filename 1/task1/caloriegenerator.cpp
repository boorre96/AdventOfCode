#include "caloriegenerator.h"

CalorieGenerator::CalorieGenerator(string &a_txtFilename) : m_elfKaloriList(a_txtFilename), m_nrOfCalElf{}, m_eachCalStored{}, m_kalories{}
{

}

ifstream& CalorieGenerator::getElfKaloriList()
{
    return this->m_elfKaloriList;
}

int CalorieGenerator::getCalorieLineFromFile()
{
    m_nrOfCalElf.clear();
    while(true)
    {
        string line;
        getline(this->m_elfKaloriList, line, '\n');
        if(!line.empty())
        {
            this->m_nrOfCalElf.append(line + "/");
        }
        else
            return calculateTotalCalories(m_nrOfCalElf);
    }
}


int CalorieGenerator::calculateTotalCalories(string &a_caloriesPicked)
{

    m_kalories = 0;
    if(a_caloriesPicked.empty())
    {
        this->m_elfKaloriList.close();
        return Error::NOMORECALORIES;
    }
    else
    {
        for(int i = 0; i < a_caloriesPicked.size(); i++)
        {
            if(a_caloriesPicked[i] != '/')
            {
                m_eachCalStored += a_caloriesPicked[i];
            }
            else
            {
                m_kalories += stoi(m_eachCalStored);
                m_eachCalStored.clear();
            }
        }
    }
    return m_kalories;
}

