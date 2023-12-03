#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char returnNumberFromString(string strNumber)
{
    if(strNumber == "one")
        return '1';
    else if(strNumber == "two")
        return '2';
    else if(strNumber == "three")
        return '3';
    else if(strNumber == "four")
        return '4';
    else if(strNumber == "five")
        return '5';
    else if(strNumber == "six")
        return '6';
    else if(strNumber == "seven")
        return '7';
    else if(strNumber == "eight")
        return '8';
    else if(strNumber == "nine")
        return '9';
    return '0';
}

int main()
{
    string numbers[]{"one","two","six",
                     "four","five","nine",
                     "three","seven","eight"};

    int indexDigitFirst = 0;
    char firstDigitChar{};
    int indexDigitLast = 0;
    char lastDigitChar{};

    string twoDigitNumber{};
    string line{};

    int sumOfValues = 0;

    string const inputFileName = "C:/Users/boris/OneDrive/Documents/Projects/adventOFCode/2023/AOC1/AOC1.txt";
    //string const inputFileName = "C:/Users/boris/OneDrive/Documents/Projects/adventOFCode/2023/AOC1/test.txt";
    ifstream calibrationDoc(inputFileName);
    while(calibrationDoc.peek() != EOF)
    {
        getline(calibrationDoc, line);
        for(auto& it : line)
        {
            // Checks digits and stores the index when found
            if(isdigit(it))
            {
                string sizeIt = &it;
                firstDigitChar = it;
                indexDigitFirst = line.size() - sizeIt.size();
                break;
            }
            indexDigitFirst = 100;
        }
        // Checks string and stores the index when found
        for(auto& it: numbers)
        {
            int placeOfStringDigit = line.find(it);
            if(placeOfStringDigit != -1)
                if(placeOfStringDigit < indexDigitFirst)
                {
                    indexDigitFirst = placeOfStringDigit;
                    firstDigitChar = returnNumberFromString(it);
                }
        }
        for(auto it = line.end(); it != line.begin() - 1; it-=1)
        {
            if(isdigit(*it))
            {
                lastDigitChar = *it;
                indexDigitLast = it - line.begin();
                break;
            }
            indexDigitLast = -1;
        }
        for(auto& it: numbers)
        {
            int placeOfStringDigit = line.rfind(it);
            if(placeOfStringDigit != -1)
                if(placeOfStringDigit > indexDigitLast)
                {
                    indexDigitLast = placeOfStringDigit;
                    lastDigitChar = returnNumberFromString(it);
                }
        }
        twoDigitNumber[0] = firstDigitChar;
        twoDigitNumber[1] = lastDigitChar;
        cout << firstDigitChar << lastDigitChar << endl;
        sumOfValues += stoi(twoDigitNumber);
        twoDigitNumber.clear();
    }
    calibrationDoc.close();
    cout << "sum = " << sumOfValues<< endl;
    return 0;
}
