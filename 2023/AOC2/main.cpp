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
    if(a_cubeColor.find("b") != -1)
    {
        if(blueCube < stoi(a_numberOfCubes))
            blueCube = stoi(a_numberOfCubes);
        if(stoi(a_numberOfCubes) > 14)
            lost = true;
    }
    else if(a_cubeColor.find("g") != -1)
    {
        if(greenCube < stoi(a_numberOfCubes))
            greenCube = stoi(a_numberOfCubes);
        if(stoi(a_numberOfCubes) > 13)
            lost = true;
    }
    else if(a_cubeColor.find("r") != -1)
    {
        if(redCube < stoi(a_numberOfCubes))
            redCube = stoi(a_numberOfCubes);
        if(stoi(a_numberOfCubes) > 12)
            lost = true;
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
        while(line.find(32) != -1)
        {
            int index = line.find(32);
            if(index > 1)
            {
                numberOfCubes += line[line.find(' ')-2];
                numberOfCubes += line[line.find(' ')-1];
                cubeColor += line[line.find(' ')+1];
                removeCubes(cubeColor, numberOfCubes);
                numberOfCubes.clear();
                cubeColor.clear();
                line.erase(0,line.find(' ')+1);
                line.erase(0,line.find(' ')+1);
            }
            else
            {
                numberOfCubes += line[line.find(' ')-1];
                cubeColor += line[line.find(' ')+1];
                removeCubes(cubeColor, numberOfCubes);
                numberOfCubes.clear();
                cubeColor.clear();
                line.erase(0,line.find(' ')+1);
                line.erase(0,line.find(' ')+1);
            }
        }
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
