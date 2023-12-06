#include <iostream>
#include <fstream>

using namespace std;
/*
Determine which games would have been possible if the bag had been loaded with
only 12 red cubes, 13 green cubes, and 14 blue cubes.
What is the sum of the IDs of those games?*/

int redCube   = 0;
int greenCube = 0;
int blueCube  = 0;
bool lost = false;

void removeCubes(string a_cubeColor, string a_numberOfCubes)
{
    if(a_cubeColor.find("blue") != -1)
    {
        if(blueCube < stoi(a_numberOfCubes))
            blueCube = stoi(a_numberOfCubes);
        lost = (stoi(a_numberOfCubes) > 14) ? true : false;
    }
    else if(a_cubeColor.find("green") != -1)
    {
        if(greenCube < stoi(a_numberOfCubes))
            greenCube = stoi(a_numberOfCubes);
        lost = (stoi(a_numberOfCubes) > 13) ? true : false;
        //greenCube -= stoi(a_numberOfCubes);
    }
    else if(a_cubeColor.find("red") != -1)
    {
        if(redCube < stoi(a_numberOfCubes))
            redCube = stoi(a_numberOfCubes);
        lost = (stoi(a_numberOfCubes) > 12) ? true : false;
        //redCube -= stoi(a_numberOfCubes);
    }
}

int main()
{
    string const inputFileName = "C:/Users/boris/OneDrive/Documents/Projects/adventOFCode/2023/AOC2/AOC2.txt";
    ifstream cubeGameDoc(inputFileName);
    string line{};
    string gameID{};
    int sumOfIDs = 0;
    int lastAmountOfCubes = 0;

    while(cubeGameDoc.peek() != EOF)
    {
        // Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
        getline(cubeGameDoc, line);
        int delimiterOne = line.find(' ') +1;
        int delimiterTwo = line.find(':');
        string cubeColor{}, numberOfCubes{};

        gameID = line.substr(delimiterOne,delimiterTwo-delimiterOne);
        line.erase(0, delimiterTwo+2);
        while (line.find(';') != -1)
        {
            string round = line.substr(0,line.find(';'));
            while (round.find(',') != -1)
            {
//                if(lost)
//                    break;
                numberOfCubes = round.substr(0,round.find(' '));
                round.erase(0,round.find(' ')+1);
                cubeColor = round.substr(0, round.find(','));
                removeCubes(cubeColor, numberOfCubes);
                round.erase(0, round.find(',')+2);
            }
//            if(lost)
//                break;
            numberOfCubes = round.substr(0,round.find(' '));
            round.erase(0,round.find(' ')+1);
            cubeColor = round.substr(round.find(' ')+1);
            removeCubes(cubeColor, numberOfCubes);
            line.erase(0, line.find(';')+2);
        }
        string round = line;
        while (round.find(',') != -1)
        {
//            if(lost)
//                break;
            numberOfCubes = round.substr(0,round.find(' '));
            round.erase(0,round.find(' ')+1);
            cubeColor = round.substr(0, round.find(','));
            removeCubes(cubeColor, numberOfCubes);
            round.erase(0, round.find(',')+2);
        }
        //if(!lost)
        //{
            numberOfCubes = round.substr(0,round.find(' '));
            cubeColor = round.substr(round.find(' ')+1);
            removeCubes(cubeColor, numberOfCubes);
        //}
        sumOfIDs += (lost == false) ? stoi(gameID) : 0;
        lastAmountOfCubes += (redCube * greenCube * blueCube);
        lost = false;
        redCube   = 0;
        greenCube = 0;
        blueCube  = 0;

    }
    cubeGameDoc.close();
    cout << "Hello World!" << endl;
    cout << sumOfIDs << endl;
    cout << lastAmountOfCubes << endl;
    return 0;
}
