#include <fstream>
#include <string>
#include <vector>
#include <algorithm>



int main()
{
    std::ifstream textFromFile("inputFile.txt");
    //std::ifstream textFromFile("example.txt");
    std::string linesFromTextFile{};
    
    // Create two lists
    std::vector<int> numberLeftSide{};
    std::vector<int> numberRightSide{};

    unsigned int totalLength = 0;
    unsigned int similarityScore = 0;

    while(std::getline(textFromFile, linesFromTextFile))
    {

        std::string testL = linesFromTextFile.substr(0, linesFromTextFile.find(" "));
        std::string testR = linesFromTextFile.substr(linesFromTextFile.find_last_of(" ")+1, linesFromTextFile.capacity());

        numberLeftSide.push_back(stoi(testL));
        numberRightSide.push_back(stoi(testR));
    
    }
    std::sort(numberLeftSide.begin(), numberLeftSide.end());
    std::sort(numberRightSide.begin(), numberRightSide.end());

    for(size_t i = 0; i < numberLeftSide.size(); i++)
    {
        int length = (numberLeftSide[i] - numberRightSide[i]);
        totalLength += (length < 0) ? length * -1 : length;   
    }
    
    for(size_t i = 0; i < numberLeftSide.size(); i++)
    {
        unsigned int similarities = 0;
        for(const auto &number : numberRightSide)
        {
            if (number == numberLeftSide[i])
            {
                similarities +=1;
            }
        }
        similarityScore += numberLeftSide[i] * similarities;         
    }

    printf("totalLength: %d \n", totalLength);
    printf("similarityScore: %d", similarityScore);

    return 0;
}