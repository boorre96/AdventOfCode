 #include "rockpaperscissorgenerator.h"

RockPaperScissorGenerator::RockPaperScissorGenerator(string& a_txtFilename) :
    m_rockPaperScissorGen(a_txtFilename)
{

}

ifstream &RockPaperScissorGenerator::getRockPaperScissorFile()
{
    return m_rockPaperScissorGen;
}

string RockPaperScissorGenerator::getRounds()
{

    while(true)
    {
        string line;
        getline(this->m_rockPaperScissorGen, line, '\n');
        if(!line.empty())
        {
            return line;
        }
        else
        {
            m_rockPaperScissorGen.close();
            return "END";
        }
    }
}
