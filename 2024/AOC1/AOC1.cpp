#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>



int main()
{
    std::ifstream textFromFile("inputFile.txt");
    //std::ifstream textFromFile("example.txt");
    std::string linesFromTextFile{};
    
    // Create two lists
    std::vector<unsigned int> numberLeftSide{};
    std::vector<unsigned int> numberRightSide{};

    // Create one hashmap
    std::map<unsigned int, unsigned int> mapInt{};

    unsigned int totalLength = 0;
    unsigned int similarityScore = 0;

    while(std::getline(textFromFile, linesFromTextFile))
    {

        std::string numberOnLeft = linesFromTextFile.substr(0, linesFromTextFile.find(" "));
        std::string numbersOnRight = linesFromTextFile.substr(linesFromTextFile.find_last_of(" ")+1, linesFromTextFile.capacity());

        numberLeftSide.push_back(stoi(numberOnLeft));
        numberRightSide.push_back(stoi(numbersOnRight));
    
    }
    std::sort(numberLeftSide.begin(), numberLeftSide.end());
    std::sort(numberRightSide.begin(), numberRightSide.end());

    for(size_t i = 0; i < numberLeftSide.size(); i++)
    {
        const int length = (numberLeftSide[i] - numberRightSide[i]);
        totalLength += (length < 0) ? length * -1 : length;

        mapInt[numberRightSide[i]] += 1;
    }
    
    for(const unsigned int &number : numberLeftSide)
    {
        similarityScore += number * mapInt[number];
    }    

    printf("totalLength: %d \n", totalLength);
    printf("similarityScore: %d", similarityScore);
    return 0;
}