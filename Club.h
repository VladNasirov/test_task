#pragma once
#include "table.h"
#include "ClubTime.h"
#include <vector>
#include <queue>

class Club
{
    public:
    void setNumberOfTables(unsigned int num);
    void setTime(ClubTime Start, ClubTime Stop);
    void setCostPerHour(unsigned int cost);

    

    private:
    unsigned int NumberOfTables;
    ClubTime start;
    ClubTime stop;
    unsigned int CostPerHour;
    std::vector<Table> tables;
    std::queue<Client> clients;
};