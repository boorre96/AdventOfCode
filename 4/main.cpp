#include <iostream>
#include <fstream>
#include <map>
#include <utility>

using namespace std;

int main()
{
    string const inputFile = "C:/Users/boris/OneDrive/Documents/Projects/adventOFCode/4/pairsInput.txt";
    ifstream assigmPairsInput(inputFile);
    string line{}, pair11{}, pair22{};
    pair <string, string> pair1, pair2;
    int amountOfTimes = 0, amountOfTimesPart2 = 0;
    while(assigmPairsInput.is_open())
    {
        getline(assigmPairsInput, line);
        if(line.empty())
            break;

        pair11 = line.substr(0,line.find(','));
        pair22 = line.substr(line.find(',')+1, line.size());

        pair1.first = pair11.substr(0, pair11.find('-'));
        pair1.second = pair11.substr(pair11.find('-')+1, pair11.size());


        pair2.first = pair22.substr(0, pair22.find('-'));
        pair2.second = pair22.substr(pair22.find('-')+1, pair22.size());

        if(stoi(pair1.first) <= stoi(pair2.first) && stoi(pair1.second) >= stoi(pair2.second))
            amountOfTimes +=1;
        else if(stoi(pair2.first) <= stoi(pair1.first) && stoi(pair2.second) >= stoi(pair1.second))
            amountOfTimes +=1;

        if(stoi(pair1.first) <= stoi(pair2.first))
        {
            if(stoi(pair1.second) >= stoi(pair2.first) || stoi(pair1.second) >= stoi(pair2.second))
                amountOfTimesPart2 +=1;
        }
        else if(stoi(pair2.first) <= stoi(pair1.first))
        {
            if(stoi(pair2.second) >= stoi(pair1.first) || stoi(pair2.second) >= stoi(pair1.second))
                amountOfTimesPart2 +=1;
        }

        pair11.clear();
        pair22.clear();
        cout << line << endl;

    }
    assigmPairsInput.close();
    cout << amountOfTimes << endl;
    cout << amountOfTimesPart2 << endl;
    cout << amountOfTimesPart2 - amountOfTimes << endl;
    return 0;
}
