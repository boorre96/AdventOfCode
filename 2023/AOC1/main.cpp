#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int sumOfValues = 0;
    string twoDigitNumber{};
    string line{};
    string const inputFileName = "C:/Users/boris/OneDrive/Documents/Projects/adventOFCode/2023/AOC1/AOC1.txt";
    ifstream calibrationDoc(inputFileName);
    while(calibrationDoc.peek() != EOF)
    {
        getline(calibrationDoc, line);
        for(auto& it : line)
        {
            if(isdigit(it))
            {
                twoDigitNumber+= it;
                break;
            }
        }
//        for(auto it = line.begin(); it != line.end(); it+=1)
//            if(isdigit(*it))
//            {
//                twoDigitNumber+= *it;
//                break;
//            }

        for(auto it = line.end(); it != line.begin() - 1; it-=1)
            if(isdigit(*it))
            {
                twoDigitNumber += *it;
                break;
            }
        cout << twoDigitNumber << endl;
        sumOfValues += stoi(twoDigitNumber);
        twoDigitNumber.clear();
    }
    calibrationDoc.close();
    cout << "sum = " << sumOfValues<< endl;
    return 0;
}
