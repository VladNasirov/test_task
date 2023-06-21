#pragma once
#include "table.h"
#include "ClubTime.h"
#include <vector>
#include <queue>

class Club
{
    public:
    void setNumberOfTables(int num);
    void setTime(ClubTime Start, ClubTime Stop);
    void setCostPerHour(int cost);

    

    private:
    int NumberOfTables;
    ClubTime start;
    ClubTime stop;
    int CostPerHour;
    std::vector<Table> tables;
    std::queue<Client> clients;
};