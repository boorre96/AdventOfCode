#include <fstream>
#include <string>
#include <deque>
#include <iostream>


int findXMASHoriz(const std::deque<std::string>& twoDarray)
{
    /*
    ---->
    <----
    */
    size_t index = 0;
    int foundXMAS = 0;

    while(twoDarray.back().find('X', index) != std::string::npos && twoDarray.back().find('X', index) < twoDarray.back().size() - 3)
    {   
        index = twoDarray.back().find('X', index);
        std::string compareStr = std::string(1, twoDarray.back().at(index)) + 
                                    std::string(1, twoDarray.back().at(index + 1)) + 
                                    std::string(1, twoDarray.back().at(index + 2)) + 
                                    std::string(1, twoDarray.back().at(index + 3));
        if("XMAS" == compareStr)
            foundXMAS++;
        index++;
    }
    index = 0;
    while(twoDarray.back().find('S', index) != std::string::npos && twoDarray.back().find('S', index) < twoDarray.back().size() - 3)
    {   
        index = twoDarray.back().find('S', index);
        std::string compareStr = std::string(1, twoDarray.back().at(index)) + 
                                    std::string(1, twoDarray.back().at(index + 1)) + 
                                    std::string(1, twoDarray.back().at(index + 2)) + 
                                    std::string(1, twoDarray.back().at(index + 3));
        if("SAMX" == compareStr)
            foundXMAS++;
        index++;
    }
    return foundXMAS;
}

int findXMASVertiDiag(const std::deque<std::string>& twoDarray)
{
    /*
        | ^
        | |
        v |
    */
    size_t index = 0;
    int foundXMAS = 0;
    while(twoDarray.front().find('X', index) != std::string::npos)
    {   
        index = twoDarray.front().find('X', index);
        if (index <= twoDarray[0].size() - 4)
        {
            std::string compareStr = std::string(1, twoDarray[0].at(index)) + 
                                     std::string(1, twoDarray[1].at(index + 1)) + 
                                     std::string(1, twoDarray[2].at(index + 2)) + 
                                     std::string(1, twoDarray[3].at(index + 3));
            if("XMAS" == compareStr)
                foundXMAS++;
        }
        
        if (index > 2 && index < twoDarray[0].size())
        {
            std::string compareStr = std::string(1, twoDarray[0].at(index)) + 
                                     std::string(1, twoDarray[1].at(index - 1)) + 
                                     std::string(1, twoDarray[2].at(index - 2)) + 
                                     std::string(1, twoDarray[3].at(index - 3));
            if("XMAS" == compareStr)
                foundXMAS++;
        }
        std::string compareStr = std::string(1, twoDarray[0].at(index)) + 
                                     std::string(1, twoDarray[1].at(index)) + 
                                     std::string(1, twoDarray[2].at(index)) + 
                                     std::string(1, twoDarray[3].at(index));
        if("XMAS" == compareStr)
            foundXMAS++;
        index++;
    }
    index = 0;
    while(twoDarray.front().find('S', index) != std::string::npos)
    {   
        index = twoDarray.front().find('S', index);
        if (index <= twoDarray[0].size() - 4)
        {
            std::string compareStr = std::string(1, twoDarray[0].at(index)) + 
                                     std::string(1, twoDarray[1].at(index + 1)) + 
                                     std::string(1, twoDarray[2].at(index + 2)) + 
                                     std::string(1, twoDarray[3].at(index + 3));
            if("SAMX" == compareStr)
                foundXMAS++;
        }
        
        if (index > 2 && index < twoDarray[0].size())
        {
            std::string compareStr = std::string(1, twoDarray[0].at(index)) + 
                                     std::string(1, twoDarray[1].at(index - 1)) + 
                                     std::string(1, twoDarray[2].at(index - 2)) + 
                                     std::string(1, twoDarray[3].at(index - 3));
            if("SAMX" == compareStr)
                foundXMAS++;
        }
        std::string compareStr = std::string(1, twoDarray[0].at(index)) + 
                                     std::string(1, twoDarray[1].at(index)) + 
                                     std::string(1, twoDarray[2].at(index)) + 
                                     std::string(1, twoDarray[3].at(index));
        if("SAMX" == compareStr)
            foundXMAS++;
        index++;
    }

    /*
    \     ^
     \   /
      v /
    */

    return foundXMAS;
}
int main()
{
    //std::fstream textFile{"example.txt"};
    std::fstream textFile{"inputFile.txt"}; 
    std::string textLine{};
    unsigned int row = 0;
    unsigned int numberOfXMAS = 0;    

    std::deque<std::string> twoDCharArray{};

    while(std::getline(textFile, textLine))
    {
        twoDCharArray.push_back(textLine);
        // collect first all 4 rows.
        if(row >= 3)
        {
        numberOfXMAS += findXMASVertiDiag(twoDCharArray); 
        twoDCharArray.pop_front();
        }
        row++;

        numberOfXMAS += findXMASHoriz(twoDCharArray);
        

    }
    printf("Number of XMAS: %d\n", row);
    printf("Number of XMAS: %d\n", numberOfXMAS);
    
    return 0;
}