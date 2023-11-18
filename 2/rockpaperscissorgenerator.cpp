 #include "rockpaperscissorgenerator.h"

rockPaperScissorGenerator::rockPaperScissorGenerator(string& a_txtFilename) :
    m_rockPaperScissorGen(a_txtFilename)
{

}

ifstream &rockPaperScissorGenerator::getRockPaperScissorFile()
{
    return m_rockPaperScissorGen;
}

string rockPaperScissorGenerator::getRounds()
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
