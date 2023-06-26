#pragma once
#include "table.h"
#include <vector>
#include <list>
#include <queue>
#include <memory>
class Club
{
    public:
    void setNumberOfTables(unsigned int num);
    void setTime(std::string line);
    void setCostPerHour(unsigned int cost);
    
    bool alreadyInTheClub(std::string name);//переписать смотря на clientlist
    bool InTheQueue();
    bool isOpen(ClubTime ct);
    bool hasFreeTables();
   
    void clientLeaves(std::string name, ClubTime ct);
    void takeTable(int tableNumber, std::shared_ptr<Client> c, ClubTime ct);
    void clearTable(std::string clientName, ClubTime ct);
    void changeTable(std::shared_ptr<Client> c, unsigned int num, ClubTime ct);
    void updateNow(ClubTime eventTime);
    

    std::shared_ptr<Client> getClientByTable(std::shared_ptr<Table> t);
    std::shared_ptr<Table> getTableByClient(std::shared_ptr<Client> t);
    ClubTime getNow();

    unsigned int getFreeTable();

    void addToQue(std::shared_ptr<Client> c);
    void popFromQue();
    std::shared_ptr<Client> getNextClient();
    bool queueTooBig();

    Club()=default;
    void addToList(std::shared_ptr<Client> c);
    std::shared_ptr<Client> getClientFromList(std::string name);
    void deleteClientFromList(std::string name);

    void printProfit();
    void printEndTime();
    void printStartTime();
    bool queIsEmpty();


    private:
    unsigned int NumberOfTables;
    ClubTime start;
    ClubTime stop;
    ClubTime Now;
    unsigned int CostPerHour;
    
    std::vector<std::pair<std::shared_ptr<Table>, std::shared_ptr<Client>>> tables;
    std::queue<std::shared_ptr<Client>> clients;

    std::list<std::shared_ptr<Client>> clientsList;
};