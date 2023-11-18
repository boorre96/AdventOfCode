#pragma once

int getChosenHandSign(int roPaSc)
{
    return (roPaSc % 44) + 1;
}

/*
Using their ASCII values.
A,B,C = 65,66,67
X,Y,Z = 88,89,90

Win: 21,24,24
Lose: 22,22,25
Draw: The rest

(21,24,24) % 3 = 0,0,0
(22,22,25) % 3 = 1,1,1
Draw = 2
*/
int calculateRoundScorePartOne(char opponent, char player)
{
    int diffInAscii = ((int)player - (int)opponent) % 3;

    if(diffInAscii == 2)
        return (3 + getChosenHandSign(player));
    else if(diffInAscii == 0)
        return (6 + getChosenHandSign(player));
    else

    return getChosenHandSign(player);
}

int calculateRoundScorePartTwo(char opponent, char player)
{
    int valueFromRound = 0;

    if(player == 'X')
    {
        valueFromRound = (opponent == 'A') ? getChosenHandSign('Z') : getChosenHandSign(opponent + 22);

    }
    else if(player == 'Y')
    {
        valueFromRound =  3 + getChosenHandSign(opponent + 23);
    }
    else
    {
        valueFromRound = (opponent == 'C') ? getChosenHandSign('X') + 6 : getChosenHandSign(opponent + 24) + 6;
    }
    return valueFromRound;
}
