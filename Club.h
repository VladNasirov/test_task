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
    bool alreadyInTheClub(std::string name);
    bool InTheQueue();
    bool isOpen(ClubTime ct);
    bool hasFreeTables();
    bool queueTooBig();
    void clientLeaves(std::string name);
    void takeTable(int tableNumber, std::shared_ptr<Client> c);
    void updateNow(ClubTime eventTime);
    ClubTime getNow();

    unsigned int getFreeTable();

    void addToQue(std::shared_ptr<Client> c);
    std::shared_ptr<Client> getNextClient();
    private:
    unsigned int NumberOfTables;
    ClubTime start;
    ClubTime stop;
    ClubTime Now;
    unsigned int CostPerHour;
    
    std::vector<std::pair<std::shared_ptr<Table>, std::shared_ptr<Client>>> tables;
    std::queue<std::shared_ptr<Client>> clients;
};