#pragma once
#include "Club.h"
void Club::setNumberOfTables(unsigned int num)
{
    NumberOfTables=num;
    for(int i=0; i<NumberOfTables; i++)
    {
        Table tb(i);
        tables.push_back(tb);
    }
}
void Club::setTime(ClubTime Start, ClubTime Stop)
{
    start=Start;
    stop=Stop;
}
void Club::setCostPerHour(unsigned int cost)
{
    CostPerHour=cost;
}