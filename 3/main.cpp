#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
void removeDuplicate(string &str)
{
    int n = size(str);
    unordered_map<char, int> exists;
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (exists.find(str[i]) == exists.end())
        {
            ans.push_back(str[i]);
            exists[str[i]]++;
        }
    }
    str = ans;
}
int getScore(char it2){
    int score=0;
    if(islower(it2))
    {
        score = it2 % 96;
    }
    else
    {
        score = (it2 % 65) + 27;
    }
    return score;
}
int findSame(string s1, string s2)
{
    int i1 = 0;
    int i2 = 0;
    int total = 0;
    for(auto it1 = s1.begin(), it2 = s2.begin(); it1 != s1.end() && it2 != s2.end();)
    {
        if(*it1 == *it2)
        {
            total += getScore(*it1);
            it2 +=1;
            it1 +=1;
        }
        else if(*it1 > *it2)
            it2 +=1;
        else
        {
            it1 +=1;
        }
    }
    return total;
}
int main()
{
    string inputFile = "C:/Users/boris/OneDrive/Documents/Projects/adventOFCode/3/rucksackItemsInput.txt";
    ifstream itemGenerator(inputFile);
    string line{};
    string item1{};
    string item2{};
    int score{0};
    while (itemGenerator.is_open())
    {
        getline(itemGenerator, line, '\n');
        if(line.empty())
            break;
        int middle = size(line)/2;
        item1 = line.substr(0,middle);
        item2 = line.substr(middle);
        sort(item1.begin(), item1.end());
        sort(item2.begin(), item2.end());
        removeDuplicate(item1);
        removeDuplicate(item2);
        score += findSame(item1, item2);

        cout << "AFTER : first: " << item1 << ", second: "<<  item2 << ", score: " << score << endl;
        line.clear();
    }
    return 0;
}
