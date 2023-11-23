#include <iostream>
#include <fstream>
#include <vector>
#include <map>
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
    string items[2] = {s1,s2};
    std::unordered_map<char, int> sameItem;
    int total = 0;
    for(int i = 0; i < 2; i++)
        for(auto it = items[i].begin(); it != items[i].end(); it++)
            sameItem[*it] +=1;

    for(auto &threeBadges : sameItem)
        total += (threeBadges.second == 2) ? getScore(threeBadges.first) : 0;

    return total;

}
int findSameBadge(string badges[])
{
    std::unordered_map<char, int> sameBadge;
    int total = 0;

    for(int i = 0; i < 3; i++)
        for(auto it = badges[i].begin(); it != badges[i].end(); it++)
            sameBadge[*it] +=1;

    for(auto &threeBadges : sameBadge)
        total += (threeBadges.second == 3) ? getScore(threeBadges.first) : 0;

    return total;


}

int main()
{

    string inputFile = "C:/Users/boris/OneDrive/Documents/Projects/adventOFCode/3/rucksackItemsInput.txt";
    ifstream itemGenerator(inputFile);
    string line{};
    string item1{};
    string item2{};
    string badges[3]{"","",""};
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
        removeDuplicate(item1);
        removeDuplicate(item2);
        removeDuplicate(line);
        score += findSame(item1, item2);

        if(count == 2)
        {
            badges[count] = line;
            score2 += findSameBadge(badges);

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
