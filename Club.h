#pragma once
#include "table.h"
#include "ClubTime.h"
#include <vector>
#include <queue>
#include <memory>
class Club
{
    public:
    void setNumberOfTables(unsigned int num);
    void setTime(ClubTime Start, ClubTime Stop);
    void setCostPerHour(unsigned int cost);
    void addToQue(Client& c);
    bool alreadyInTheClub(std::string name);
    bool InTheQueue();
    bool isOpen(ClubTime ct);
    bool hasFreeTables();
    bool queueTooBig();
    void clientLeaves(std::string name);


    private:
    unsigned int NumberOfTables;
    ClubTime start;
    ClubTime stop;
    unsigned int CostPerHour;
    std::vector<std::pair<Table, Client>> tables;
    std::queue<Client> clients;
};