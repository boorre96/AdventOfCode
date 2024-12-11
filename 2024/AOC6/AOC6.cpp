#include <vector>
#include <string>
#include <fstream>

void printMap(const std::vector<std::vector<char>>& guardMap)
{
    for(std::vector<char> vectorChar : guardMap)
    {
        for(char character : vectorChar)
        {
            printf("%c",character);
        }
        printf("\n");
    }
    printf("------------------------------------------\n");

}

void printMap(const std::vector<std::vector<char>>& guardMap, int& countedPath)
{
    for(std::vector<char> vectorChar : guardMap)
    {
        for(char character : vectorChar)
        {
            if(character == 'X')
                countedPath++;
            printf("%c",character);
        }
        printf("\n");
    }
    printf("------------------------------------------\n");

}
int main()
{
    std::vector<std::vector<char>> guardMap{};
    bool GameOver = false;
    //std::ifstream textFile("example.txt");
    std::ifstream textFile("inputFile.txt");
    std::string textline{};
    unsigned int posX = 0;
    unsigned int posY = 0;

    enum Direction
    {
        UP,
        RIGHT,
        DOWN,
        LEFT
    };

    Direction direction = Direction::UP;

    while (std::getline(textFile, textline))
    {
        std::vector<char> charactersFromString{};
        for(int i = 0; i < (int)textline.size(); i++)
        {
            charactersFromString.push_back(textline[i]);

            // Find the position of guard
            if(textline[i] == '^')
            {
                posX = (unsigned int)i;
                posY = (unsigned int)guardMap.size();
            }
        }
        guardMap.push_back(charactersFromString);
    }
    while(!GameOver)
    {
        //printMap(guardMap);
        switch (direction)
        {
        case UP:
            if(posY==0)
            {
                GameOver = true;
                guardMap[posY][posX] = 'X';
                break;
            }
            if(guardMap[posY-1][posX] != '#')
            {
                guardMap[posY][posX] = 'X';
                posY--;
                guardMap[posY][posX] = '^';     
            }
            else
            {
            direction = Direction::RIGHT;
            guardMap[posY][posX] = '>'; 
            }
            
            break;
        case RIGHT:
            if(posX == guardMap[posY].size() - 1)
            {
                GameOver = true;
                guardMap[posY][posX] = 'X';
                break;
            }
            if(guardMap[posY][posX+1] != '#')
            {
                guardMap[posY][posX] = 'X';
                posX++;
                guardMap[posY][posX] = '>';     
            }
            else
            {
            direction = Direction::DOWN;
            guardMap[posY][posX] = 'v'; 
            }
            break;
        case DOWN:
            if(posY==guardMap.size() - 1)
            {
                GameOver = true;
                guardMap[posY][posX] = 'X';
                break;
            }
            if(guardMap[posY+1][posX] != '#')
            {
                guardMap[posY][posX] = 'X';
                posY++;
                guardMap[posY][posX] = 'v';     
            }
            else
            {
            direction = Direction::LEFT;
            guardMap[posY][posX] = '<'; 
            }
            break;
        case LEFT:
            if(posX == 0)
            {
                GameOver = true;
                guardMap[posY][posX] = 'X';
                break;
            }
            if(guardMap[posY][posX-1] != '#')
            {
                guardMap[posY][posX] = 'X';
                posX--;
                guardMap[posY][posX] = '<';     
            }
            else
            {
            direction = Direction::UP;
            guardMap[posY][posX] = '^'; 
            }
            break;
        
        default:
            break;
        }
    }


    int countedPath = 0;
    printMap(guardMap, countedPath);
    printf("counted path: %d\n", countedPath);
    
    return 0;
}