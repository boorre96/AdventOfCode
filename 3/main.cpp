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
int findSame(string s1, string s2, string s3)
{
    int i1 = 0;
    int i2 = 0;
    int i3 = 0;
    int total = 0;

    for(auto it1 = s1.begin(); it1 != s1.end();)
    {
        for(auto it2 = s2.begin(); it2 != s2.end();)
        {
            if(*it1 == *it2)
            {
                for(auto it3 = s3.begin(); it3 != s3.end();){
                    if(*it2==*it3)
                    {
                        total += getScore(*it3);
                        break;
                    }
                    it3+=1;
                }
                break;
            }
            it2 +=1;
        }
        it1 +=1;
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
    string badges[]{"","",""};
    int score{0};
    int score2{0};
    int count{0};
    while (itemGenerator.is_open())
    {
        getline(itemGenerator, line, '\n');
        if(line.empty())
            break;
        item1 = line.substr(0, line.size()/2);
        item2 = line.substr(line.size()/2, line.size());
        sort(item1.begin(), item1.end());
        sort(item2.begin(), item2.end());
        sort(line.begin(), line.end());
        removeDuplicate(item1);
        removeDuplicate(item2);
        removeDuplicate(line);
        score += findSame(item1, item2);

        if(count == 2)
        {
            badges[count] = line;
            score2 += findSame(badges[0],badges[1],badges[2]);

        }
        badges[count] = line;
        line.clear();
        count = (count + 1) % 3;
    }
    itemGenerator.close();
    cout << "Score 1: "<< score << endl;
    cout << "Score 2: "<< score2 << endl;
    return 0;
}
