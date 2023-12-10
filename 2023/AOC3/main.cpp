#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "numberstartstop.h"
#include "symbolstartstop.h"

using namespace std;

int findSymbol(vector<vector<SymbolStartStop>> const& a_partSymbols,
               vector<vector<NumberStartStop>> const& a_partNumbers,
               int const a_row)
{
    int sum = 0;
    if(a_partSymbols[a_row].empty())
        return sum = 0;
    else
    {
        if(a_row == 0)
        {
            int l = (a_row == 0) ? 1 : -1;
            for(int i = 0; i < a_partSymbols[a_row].size(); i+=1)
            {
                auto symbolPos = a_partSymbols[a_row][i].startPos();
                for (int j = 0; j < a_partNumbers.size(); ++j)
                {
                    auto number = a_partNumbers[a_row][i];
                    if(symbolPos+1 == number.startPos() ||
                        symbolPos-1 == number.stopPos())
                    {
                        cout << number.getNumber() << endl;
                        sum +=number.getNumber();
                    }
                }
                if(a_partNumbers[a_row+l].empty())
                    break;
                for (int j = 0; j < a_partNumbers.size(); ++j)
                {
                    auto number = a_partNumbers[a_row+l][i];
                    if(symbolPos+1 >= number.startPos() &&
                        symbolPos-1 <= number.stopPos())
                    {
                        cout << number.getNumber() << endl;
                        sum +=number.getNumber();
                    }
                }
            }
        }
        else
        {
            for(int i = 0; i < a_partSymbols[a_row].size(); i+=1)
            {
                auto symbolPos = a_partSymbols[a_row][i].startPos();
                if(!a_partNumbers[a_row].empty())
                {
                    for(int j = 0; j < a_partNumbers[a_row].size(); j+=1)
                    {
                        auto number = a_partNumbers[a_row][j];
                        if(symbolPos+1 == number.startPos() ||
                            symbolPos-1 == number.stopPos())
                        {
                            cout << number.getNumber() << endl;
                            sum +=number.getNumber();
                        }
                    }
                }
                if(!a_partNumbers[a_row+1].empty())
                {
                    for(int j = 0; j < a_partNumbers[a_row+1].size(); j+=1)
                    {
                        auto number = a_partNumbers[a_row+1][j];
                        if(symbolPos+1 >= number.startPos() &&
                            symbolPos-1 <= number.stopPos())
                        {
                            cout << number.getNumber() << endl;
                            sum +=number.getNumber();
                        }
                    }
                }

                if(!a_partNumbers[a_row-1].empty())
                {
                    for(int j = 0; j < a_partNumbers[a_row-1].size(); j+=1)
                    {
                        auto number = a_partNumbers[a_row-1][j];
                        if(symbolPos+1 >= number.startPos() &&
                            symbolPos-1 <= number.stopPos())
                        {
                            cout << number.getNumber() << endl;
                            sum +=number.getNumber();
                        }
                    }
                }
            }
        }

    }

    //

    return sum;
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
    vector<vector<NumberStartStop>> partNumbers;
    vector<vector<SymbolStartStop>> partSymbols;
    //string const filename = "C:/Users/boris/OneDrive/Documents/Projects/adventOFCode/2023/AOC3/test.txt";
    string const filename = "C:/Users/boris/OneDrive/Documents/Projects/adventOFCode/2023/AOC3/AOC3.txt";
    ifstream partNumberGenerator(filename);
    int sum1 = 0;
    int sum2 = 0;
    while (partNumberGenerator.peek() != EOF)
    {
        // Fill 2d vector with numbers
        string line{};
        string number{};
        getline(partNumberGenerator, line);
        vector<NumberStartStop> rowN;
        vector<SymbolStartStop> rowS;
        int startPos{}, endPos{};
        for(int i = 0; i < line.size(); i+= 1)
        {
            if(isdigit(line[i]))
            {
                startPos = i;
                while(isdigit(line[i]))
                {
                    number.push_back(line[i]);
                    i+=1;
                }
                endPos = i-1;
                i-=1;
                NumberStartStop numberFromList(stoi(number), startPos, endPos);
                rowN.push_back(numberFromList);
                number.clear();
            }
            else if(!isdigit(line[i]) && line[i] != '.')
            {
                SymbolStartStop numberFromList(-1, i, i);
                rowS.push_back(numberFromList);
                number.clear();
            }
        }
        partNumbers.push_back(rowN);
        partSymbols.push_back(rowS);
    }
    partNumberGenerator.close();
    for(auto rows = 0; rows < partNumbers.size(); rows+=1)
    {
        int sum =findSymbol(partSymbols, partNumbers, rows);
        sum1 += sum;
    }
    cout << sum1 << endl;
    return 0;
}//529870 to high
