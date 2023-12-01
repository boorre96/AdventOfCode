#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int main()
{
    string const pathToFile = "C:/Users/boris/OneDrive/Documents/Projects/adventOFCode/5/stackInput.txt";
    ifstream stackGenerator(pathToFile);
    string line{0};
    vector<vector<char>> crates;
    bool insertingCrates = true;
    bool movingCrates = false;
    getline(stackGenerator, line);
    while(stackGenerator.is_open())
    {
        while(insertingCrates){
            getline(stackGenerator, line);
            if (line.empty())
                break;
            cout << line << endl;
        }
        insertingCrates = false;
        movingCrates = true;
        while(movingCrates)
        {
            // Checks if the end of file
            if(stackGenerator.peek() == EOF)
            {
                cout << "End" << endl;
                break;
            }
            getline(stackGenerator, line);
            if (line.empty())
                break;
            cout << line << endl;
        }
        break;

    }
    stackGenerator.close();
    cout << line << endl;
    cout << "Hello World!" << endl;
    return 0;
}
