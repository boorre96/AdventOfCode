#include <iostream>
#include "calculateFunctions.h"
#include "rockpaperscissorgenerator.h"



using namespace std;
std::string c_nameOfFile = "C:/Users/boris/OneDrive/Documents/Projects/adventOFCode/2/rockPaperScissorInput.txt";
int main()
{
    int scorePartOne = 0;
    int scorePartTwo = 0;
    rockPaperScissorGenerator rockPaperScissor(c_nameOfFile);
    while(rockPaperScissor.getRockPaperScissorFile().is_open())
    {
        string chosenHandsigns = rockPaperScissor.getRounds();
        if(chosenHandsigns == "END")
            break;
        scorePartOne += calculateRoundScorePartOne(chosenHandsigns[0], chosenHandsigns[2]);
        scorePartTwo += calculateRoundScorePartTwo(chosenHandsigns[0], chosenHandsigns[2]);
    }
    cout << "Part 1: The total score is: " << scorePartOne << endl;
    cout << "Part 2: The total score is: " << scorePartTwo << endl;


    return 0;
}
