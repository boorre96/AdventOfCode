#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool findSymbol(vector<vector<char>> const& a_partNumbers, int a_start, int a_end, int a_row)
{
    if(a_row == 0 || a_row == a_partNumbers.size()-1)
    {
        int l = (a_row == 0) ? 1 : -1;

        for(int i = 0; i < a_partNumbers[a_row].size(); i+=1)
        {
            if(a_partNumbers[a_row][i] != '.' && !isdigit(a_partNumbers[a_row][i]))
                if(i+1 == a_start || i-1 == a_end)
                    return true;
            if(a_partNumbers[a_row+l][i] != '.' && !isdigit(a_partNumbers[a_row+l][i]))
                if(i+1 >= a_start && i-1 <= a_end)
                    return true;
        }
    }
    else
    {
        for(int i = 0; i < a_partNumbers[a_row].size(); i+=1)
        {
            if(a_partNumbers[a_row][i] != '.' && !isdigit(a_partNumbers[a_row][i]))
                if(i+1 == a_start || i-1 == a_end)
                    return true;
            if(a_partNumbers[a_row-1][i] != '.' && !isdigit(a_partNumbers[a_row-1][i]))
                if(i+1 >= a_start && i-1 <= a_end)
                    return true;
            if(a_partNumbers[a_row+1][i] != '.' && !isdigit(a_partNumbers[a_row+1][i]))
                if(i+1 >= a_start && i-1 <= a_end)
                    return true;
        }
    }
    return false;
}

int main()
{
    /*
467..114..
...*......
..35..633.
......#...
617*......
.....+.58.
..592.....
......755.
...$.*....
.664.598..*/
    vector<vector<char>> partNumbers;
    //string const filename = "C:/Users/boris/OneDrive/Documents/Projects/adventOFCode/2023/AOC3/test.txt";
    string const filename = "C:/Users/boris/OneDrive/Documents/Projects/adventOFCode/2023/AOC3/AOC3.txt";
    ifstream partNumberGenerator(filename);
    int sum1 = 0;
    int sum2 = 0;
    int startingPos{}, endingPos{}, posSymb{};

    string number = {};
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
    for(int i = 0; i < partNumbers.size(); i+=1)
        for(int j = 0; j <partNumbers[i].size(); j+= 1)
        {
            //            if(!isdigit(partNumbers[i][j]) && partNumbers[i][j] != '.')
            //            {
            //                posSymb = j;
            //                if(findSymbol2(partNumbers, posSymb, i))
            //                {
            //                    cout << "Found task 2" << endl;
            //                }
            //            }
            if(isdigit(partNumbers[i][j]))
            {
                startingPos = j;
                while(isdigit(partNumbers[i][j]))
                {
                    number.push_back(partNumbers[i][j]);
                    j+=1;
                }
                endingPos = j-1;
                if(findSymbol(partNumbers, startingPos, endingPos, i))
                {
                    cout << number << endl;
                    sum1+= stoi(number);
                }
                number.clear();
            }

        }

    cout << sum1 << endl;
    return 0;
}//529870 to high
