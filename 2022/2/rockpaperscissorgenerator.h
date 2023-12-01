#pragma once
#include <fstream>
#include <string>

using namespace std;

class RockPaperScissorGenerator
 {
public:
    RockPaperScissorGenerator(string &txtFilename);

    ifstream& getRockPaperScissorFile();
    string getRounds();
private:
    ifstream m_rockPaperScissorGen;

};

