#include "symbolstartstop.h"

SymbolStartStop::SymbolStartStop(int a_number, int a_start, int a_stop) :
    m_number(a_number)
    ,   m_startPos(a_start)
    ,   m_stopPos(a_stop)
{

}

int SymbolStartStop::startPos() const
{
    return m_startPos;
}

void SymbolStartStop::setStartPos(int newStart)
{
    m_startPos = newStart;
}

int SymbolStartStop::getNumber() const
{
    return m_number;
}

void SymbolStartStop::setNumber(int newNumber)
{
    m_number = newNumber;
}

int SymbolStartStop::stopPos() const
{
    return m_stopPos;
}

void SymbolStartStop::setStopPos(int newStop)
{
    m_stopPos = newStop;
}
