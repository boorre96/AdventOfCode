#pragma once
#include <fstream>
#include <string>

using namespace std;

class rockPaperScissorGenerator
 {
public:
    rockPaperScissorGenerator(string &txtFilename);

    ifstream& getRockPaperScissorFile();
    string getRounds();
private:
    ifstream m_rockPaperScissorGen;

};

