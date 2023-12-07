#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<char>> partNumbers;
    string const filename = "C:/Users/boris/OneDrive/Documents/Projects/adventOFCode/2023/AOC3/test.txt";
    //string const filename = "C:/Users/boris/OneDrive/Documents/Projects/adventOFCode/2023/AOC3/AOC3.txt";
    ifstream partNumberGenerator(filename);
    int row = 0;
        while (partNumberGenerator.peek() != EOF)
        {
            // Fill 2d vector
            string line;
            getline(partNumberGenerator, line);
            vector<char> row;
            row.assign(line.begin(), line.end());
            partNumbers.push_back(row);
        }
    partNumberGenerator.close();
        int coll = 0;
        for(auto& row : partNumbers)
        {
            for(auto& col : row)
                cout << col;
            cout << endl;
        }

    return 0;
}
