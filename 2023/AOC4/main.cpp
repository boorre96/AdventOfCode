#include <iostream>
#include <fstream>
#include <map>
#include <cmath>
using namespace std;

void storeNumbersInHashmap(map<string, int>& a_myNumbers, string const& a_mynumber)
{
    for(int i = 0; i < a_mynumber.size(); i+=3)
    {
        string myNum{a_mynumber[i],a_mynumber[i+1]};
        a_myNumbers.insert(pair<string, int>(myNum, 0));
    }
}
int main()
{
    //string const filename = "C:/Users/boris/OneDrive/Documents/Projects/adventOFCode/2023/AOC4/test.txt";
    string const filename = "C:/Users/boris/OneDrive/Documents/Projects/adventOFCode/2023/AOC4/AOC4.txt";
    ifstream scratchList(filename);
    map<string,int> mapMyNumbers;
    int sum = 0;
    while(scratchList.peek() != EOF)
    {
        string line{};
        getline(scratchList, line);
        string myNumber = line.substr(line.find(':')+2, line.find('|') - line.find(':')-2);
        storeNumbersInHashmap(mapMyNumbers, myNumber);
        string winningNumbers = line.substr(line.find('|')+2, line.size() - line.find(':'));
        for(int i = 0; i < winningNumbers.size(); i+=3)
        {
            string win{winningNumbers[i],winningNumbers[i+1]};
            if(mapMyNumbers.find(win) != mapMyNumbers.end())
            {
                mapMyNumbers[win]+=1;
            }
        }
        int sameNumber{0};
        for(auto it : mapMyNumbers)
        {
            cout << it.second << " ";
            if(it.second > 0)
            {
                if(sameNumber == 0)
                {
                    sameNumber =1;
                }
                else
                    sameNumber +=sameNumber;

            }
        }
        sum += sameNumber;
        mapMyNumbers.clear();
        cout << endl;
        mapMyNumbers.clear();


        //cout << myNumber << endl;
        //cout << winningNumbers << endl;
        //cout << winningNumbers << endl;

    }

    scratchList.close();
    cout << sum << endl;
    return 0;
}
