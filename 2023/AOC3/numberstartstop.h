#ifndef NUMBERSTARTSTOP_H
#define NUMBERSTARTSTOP_H


class NumberStartStop
{
public:
    NumberStartStop(int a_number, int a_start, int a_stop);

    int startPos() const;
    void setStartPos(int newStart);

    int getNumber() const;
    void setNumber(int newNumber);

    int stopPos() const;
    void setStopPos(int newStop);

private:
    int m_startPos = 0;
    int m_stopPos  = 0;
    int m_number  = 0;
};

#endif // NUMBERSTARTSTOP_H
