#include <fstream>
#include <string>

bool isDigits(const std::string& str)
{
    for (const char character : str) {
        if (!(character >= 48 && character <= 57)) {
            return false;
        }
    }
    return true;
}

int main()
{

    std::ifstream textFile("inputFile.txt");
    //std::ifstream textFile("example.txt");
    std::string textLine{};
    unsigned int productOf = 0;

    while(std::getline(textFile, textLine))
    {
        
        printf("Line: %s\n", textLine.c_str());
        /*
        * Tre stadier
        1. hitta 'mul('
        2. hitta ','
        3. hitta ')'

        1-3 digit number
        Sen kolla ifall substringet mellan är siffror, ifall det är det multiplicera dem.
        */
        size_t index           = 0;
        size_t findMul         = 0;
        size_t commaSign       = 0;
        size_t findLastParant  = 0;
        

        while(true)
        {
            if(textLine.find("mul(", index) != std::string::npos)
            {
                findMul = textLine.find("mul(", index) + 3;
                if(textLine.find(",", findMul) != std::string::npos)
                {
                    commaSign = textLine.find(",",findMul);
                    
                    // kolla ifall det är mer än 3 characters
                    if( 2 > commaSign - findMul || commaSign - findMul > 4 )
                    {
                        index = findMul + 3;
                        continue;
                    }
                    if(textLine.find(")", commaSign) != std::string::npos)
                    {
                        findLastParant = textLine.find(")", commaSign);
                        // kolla ifall det finns mer än 3 characters
                        if( findLastParant - commaSign < 2 || findLastParant - commaSign > 4)
                        {
                            index = commaSign + 3;
                            continue;
                        }
                        else
                        {
                            // Här kollar vi ifall substrängerna inne håller siffror.
                            std::string nummer1 = textLine.substr(findMul + 1, commaSign - findMul - 1);
                            std::string nummer2 = textLine.substr(commaSign + 1, findLastParant - commaSign - 1);

                            if(isDigits(nummer1) && isDigits(nummer2))
                            {
                                productOf += stoi(nummer1) * stoi(nummer2);
                            }

                            index = findLastParant;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }     
            }
            else
            {
                break;
            }
            

        }
    }
    printf("Product of: %d\n", productOf);
    
    return 0;
}