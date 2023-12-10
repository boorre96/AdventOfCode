#include <iostream>
#include <fstream>
#include <map>
#include <cmath>
#include <vector>
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
    int cardNummer[300]{};
    int sum = 0;
    int sum2 = 0;
    int iteration = 0;
    while(scratchList.peek() != EOF)
    {

        string line{};
        getline(scratchList, line);
        string myNumber = line.substr(line.find(':')+2, line.find('|') - line.find(':')-2);
        storeNumbersInHashmap(mapMyNumbers, myNumber);
        string winningNumbers = line.substr(line.find('|')+2, line.size() - line.find(':'));
        cardNummer[iteration] += 1;
        for(int i = 0; i < winningNumbers.size(); i+=3)
        {
            string win{winningNumbers[i],winningNumbers[i+1]};
            if(mapMyNumbers.find(win) != mapMyNumbers.end())
            {
                mapMyNumbers[win]+=1;
            }
        }
        int sameNumber{0};
        for(auto &it : mapMyNumbers)
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

        for(int i = 0; i < cardNummer[iteration]; i+=1)
        {
            int a = 0;
            for(auto& nas : mapMyNumbers)
            {
                if(nas.second == 1)
                    a+=1;
            }
            for(int j = 1; j<=a; j+=1)
                cardNummer[iteration+j] += 1;

        }
        mapMyNumbers.clear();
        iteration+=1;
//        if(iteration ==130)
//            cout << endl;
        /*
        Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53
        Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19
        Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1
        Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83
        Card 5: 87 83 26 28 32 | 88 30 70 12 93 22 82 36
        Card 6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11
        */
    }
    scratchList.close();
    int total = 0;
    for(auto tot: cardNummer)
        total+=tot;
    cout << sum <<" : " <<  total<< endl;
    return 0;
}
