#include "numberstartstop.h"

NumberStartStop::NumberStartStop(int a_number, int a_start, int a_stop) :
    m_number(a_number)
,   m_startPos(a_start)
,   m_stopPos(a_stop)
{

}

int NumberStartStop::startPos() const
{
    return m_startPos;
}

void NumberStartStop::setStartPos(int newStart)
{
    m_startPos = newStart;
}

int NumberStartStop::getNumber() const
{
    return m_number;
}

void NumberStartStop::setNumber(int newNumber)
{
    m_number = newNumber;
}

int NumberStartStop::stopPos() const
{
    return m_stopPos;
}

void NumberStartStop::setStopPos(int newStop)
{
    m_stopPos = newStop;
}
