#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <iostream>

int main()
{

    //std::ifstream textFile("example.txt");
    std::ifstream textFile("inputFile.txt");
    std::string textline{};
    bool pageRule = true;
    int totalScore = 0;


    std::map<std::string, std::string> pagePairSet{};
    enum ReadingState
    {
        PAGEORDERINGRULE,
        UPDATE
    };

    ReadingState readState = PAGEORDERINGRULE;
    while (std::getline(textFile, textline))
    {
        if(textline.size() == 0)
        {
            readState = UPDATE;
            continue;
        }
        if (readState == ReadingState::PAGEORDERINGRULE)
        {
            pagePairSet[textline.substr(0,2)] += textline.substr(3,textline.size()) + ' ';
            
        }
        else
        {
            //// Textline std::string "75,47,61,53,29"
            //// set [75] = std::string 75: 29 53 47 61 13
            pageRule = true;
            int index = 0;
            std::vector<int> numbersVector{};
            while(textline.find(',', index) != std::string::npos)
            {
                std::string setNumber = textline.substr(index, 2);
                index = textline.find(',', index);
                numbersVector.push_back(std::stoi(setNumber));
                if(index > textline.size() - 2)
                {

                    printf("True\n");
                    break;
                }
                std::string setStringt = pagePairSet[setNumber];
                // det ska vara tvärtom
                int findIndex = index;
                while(textline.find(',', findIndex) != std::string::npos)
                {
                    std::string subset = textline.substr(textline.find(',', findIndex)+1, 2);
                    findIndex += textline.find(',', findIndex);
                    if(setStringt.find(subset) == std::string::npos)
                    {
                        printf("fail\n");
                        pageRule = false;
                    }
                }
                if(pageRule)
                {
                    index++;
                }
                else
                    break;
            }
            if(pageRule)
            {
                //"75,47,61,53,29"
                totalScore += numbersVector[(numbersVector.size()/2)];
            }
        }
    }
    printf("numbersScore: %d\n", totalScore);
    
    return 0;
}
// 29 53 47 61 13
// 75,47,61,53,29

// 97,61,53,29,13
// 75,29,13
// 75,97,47,61,53
// 61,13,29
// 97,13,75,29,47