#include <string>
#include <vector>
#include <fstream>

// try with recursion
void calculateRecursion(const std::vector<long long int>&numbers, int index, long long int totalSum, long long int comparedSum, bool& ok)
{
    if((int)numbers.size() == index)
    {
        if(totalSum == comparedSum)
        {
            ok = true;
            return;
        }
        return;
    }
    calculateRecursion(numbers, index+1, totalSum + numbers[index], comparedSum, ok);
    calculateRecursion(numbers, index+1, totalSum * numbers[index], comparedSum, ok);
}

long long int calculateBitmask(const std::vector<long long int>& numbers, long long int sum)
{
    // number of combinations
    // numbers: 2,5
    int numberOfCombinations = 1 << ((int)numbers.size() - 1 );
    for (int mask = 0; mask < numberOfCombinations; ++mask) {
        long long int result = numbers[0]; // Start with the first number
        for (int i = 0; i < (int)numbers.size()- 1; ++i) {
            if (mask & (1 << i)) {
                // If the i-th bit is set, use '+'
                result += numbers[i + 1];
            } else {
                // If the i-th bit is not set, use '*'
                result *= numbers[i + 1];
            }
        }
        if(result == sum)
            return sum;
    }
    return 0;
}

int main()
{
    std::string textline;
    //std::fstream textFile("example.txt");
    std::fstream textFile("inputFile.txt");
    long long int score = 0;

    while(std::getline(textFile, textline))
    {
        printf("%s\n", textline.c_str());
        
        bool sum = true; 
        long long int sumInt = 0;
        long long int singelNumber = 0;
        std::vector<long long int> numbers{};

        for (int i = 0; i < (int)textline.size(); i++)
        {
            if(sum)
            {
                if(std::isdigit(textline.at(i)))
                {
                    sumInt = sumInt * 10 + (textline[i] - '0');
                }
                else
                {
                    sum = false;
                    i++;
                }
            }
            else
            {
                if(std::isdigit(textline.at(i)))
                {
                    singelNumber = singelNumber * 10 + (textline[i] - '0');
                }
                else
                {
                    numbers.push_back(singelNumber);
                    singelNumber = 0;
                }
            }
        }
        numbers.push_back(singelNumber);

        // calculation
        score += calculateBitmask(numbers, sumInt);
        bool ok = false;
        // 1708857123053
        // 1708857123053
        // calculateRecursion(numbers, 1, numbers[0], sumInt, ok);
        // if(ok)
        // {
        //     score+=sumInt;
        // }
        
    }

    printf("score: %lld", score);
    return 0;
}