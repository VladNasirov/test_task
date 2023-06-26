#include "Club.h"

#include <sstream>
#include <iomanip>
#include <algorithm>
void Club::setNumberOfTables(unsigned int num)
{
    NumberOfTables=num;
    for(int i=0; i<NumberOfTables; i++)
    {
        std::shared_ptr<Table> tb=std::make_shared<Table>(i+1);
        std::shared_ptr<Client> c=std::make_shared<Client>();
        tables.push_back(std::make_pair(tb, c));
    }
}
void Club::setTime(std::string line)
{
    std::string startTime, stopTime;
    std::istringstream iss(line);
    iss>>startTime;
    iss.ignore(1);
    iss>>stopTime;
    start.deserialize(startTime);
    stop.deserialize(stopTime);
}
void Club::setCostPerHour(unsigned int cost)
{
    CostPerHour=cost;
}

void Club::addToQue(std::shared_ptr<Client> c)
{
    clients.push(c);
}
void Club::popFromQue()
{
    clients.pop();
}

bool Club::alreadyInTheClub(std::string name)//TODO просто в клубе
{
    for(int i=0; i<tables.size(); i++)//проверка занятых компьютеров
    {
        if(tables[i].second->getName()==name)
        {
            return true;
        }
    }
    if (!clients.empty()) 
    {
        std::queue<std::shared_ptr <Client>> tempQueue = clients; // Создаем временную копию очереди
        while (!tempQueue.empty()) {
            auto client = tempQueue.front(); // Получаем ссылку на текущего клиента
            if (client->getName() == name) 
            {
                return true; // Клиент с заданным именем найден
            }
            tempQueue.pop(); // Удаляем текущего клиента из временной очереди
        }
    }
    for(auto client:clientsList)
    {
        if(client->getName()==name)
        {
            return true;
        }
    }
    return false;
}

bool Club::isOpen(ClubTime ct)
{
   if (ct.getHours() > start.getHours() && ct.getHours() < stop.getHours()) {
        // Клиент пришел внутри часов работы
        return true;
    } else if (ct.getHours() == start.getHours() && ct.getMinutes() >= start.getMinutes()) {
        // Клиент пришел в момент начала работы или позже
        return true;
    } else if (ct.getHours() == stop.getHours() && ct.getMinutes() <= stop.getMinutes()) {
        // Клиент пришел в момент окончания работы или раньше
        return true;
    } else {
        // Клиент пришел до начала работы или после окончания
        return false;
    }
}
bool Club::hasFreeTables()
{
    for(int i=0; i<tables.size(); i++)
    {
        if(tables[i].first->getTableState()==TableState::Empty)
        {
            return true;
        }
    }
    return false;
}

bool Club::queueTooBig()
{
    if(clients.size()>NumberOfTables)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Club::takeTable(int tableNumber, std::shared_ptr<Client> c, ClubTime ct)
{
    for(int i=0; i<tables.size(); i++)
    {
        if(tables[i].first->getTableNumber()==tableNumber&&tables[i].first->getTableState()==TableState::Empty)
        {
            tables[i].second=c;
            tables[i].second->setClientState(ClientState::Playing);
            tables[i].first->OccupyTable(ct);
            return;
        }
        else if(tables[i].first->getTableNumber()==tableNumber&&tables[i].first->getTableState()==TableState::Occupied)
        {
            throw("PlaceIsBusy");
        }
    }

}

void Club::clientLeaves(std::string name, ClubTime ct)//TODO удаление из клуба, подсчет выручки
{
    //Освобождение стола
   for (auto& pair : tables) {
     if (pair.second->getName() == name) {
        pair.second.reset();
        pair.first->FreeTable(ct);
        break;
     }
   }
   //Освобождение очереди
   std::queue<std::shared_ptr<Client>> tempQueue;
    while (!clients.empty()) {
        std::shared_ptr<Client> frontClient = clients.front();
        clients.pop();

        if (frontClient->getName() != name) {
            tempQueue.push(frontClient);
        }
    }

    clients = std::move(tempQueue); // Замена исходной очереди временной очередью
    deleteClientFromList(name);
   
}
void Club::updateNow(ClubTime eventTime)
{
        Now=eventTime;
}

ClubTime Club::getNow()
{
        return Now;
}

std::shared_ptr<Client> Club::getNextClient()
{
        std::shared_ptr<Client> client=clients.front();
        clients.pop();
        return client;
}
unsigned int Club::getFreeTable()
{
    for(auto& pair : tables)
    {
        if(pair.first->getTableState()==TableState::Empty)
        {
            return pair.first->getTableNumber();
        }
    }
}

void Club::addToList(std::shared_ptr<Client> c)
{
        clientsList.push_back(c);
}

std::shared_ptr<Client> Club::getClientFromList(std::string name)
{
        for (const auto& client : clientsList) {
        // Доступ к элементу внутри цикла
        {
            if(client->getName()==name)
            {
                return client;
            }
        }
        }
}
void Club::deleteClientFromList(std::string name)
{
    for (const auto& client : clientsList) {
    // Доступ к элементу внутри цикла
    {
        if(client->getName()==name)
        {
            clientsList.remove(client);
            return;
        }
    }
    }
}
std::shared_ptr<Client> Club::getClientByTable(std::shared_ptr<Table> t)
{
        for(const auto& pair: tables)
        {
            if(pair.first==t)
            {
                return pair.second;
            }
        }
}
std::shared_ptr<Table> Club::getTableByClient(std::shared_ptr<Client> c)
{
        for(const auto& pair: tables)
        {
            if(pair.second==c)
            {
                return pair.first;
            }
        }
}
  

void Club::clearTable(std::string clientName, ClubTime ct)
{
        for(int i=0; i<tables.size(); i++)
        {
            if(tables[i].second->getName()==clientName)
            {
                tables[i].first->FreeTable(ct);
                tables[i].second->setClientState(ClientState::None);
                tables[i].second.reset();
            }
        }
}
void Club::changeTable(std::shared_ptr<Client> c, unsigned int num, ClubTime ct)
{
        std::shared_ptr<Table> currentTab=getTableByClient(c);
        if(currentTab->getTableNumber()!=num)
        {

            takeTable(num, c, ct);
            for(auto& pair: tables)
            {
                if(pair.first==currentTab)
                {
                   pair.first->FreeTable(ct);
                   pair.second.reset();
                }
            }
        }
        else
        {
            throw("PlaceIsBusy");
        }
}

bool Club::queIsEmpty()
{
    if(clients.empty())
    {
        return true;
    }
    else
    {
    return false;
    }
}
bool compareByName(const std::pair<std::shared_ptr<Table>, std::shared_ptr<Client>> pair1, const std::pair<std::shared_ptr<Table>, std::shared_ptr<Client>> pair2) {
        return pair1.second->getName() < pair2.second->getName();
}
void Club::printProfit()
{
    //std::sort(tables.begin(), tables.end(), compareByName);
    for(auto pair: tables)
    {
        if(pair.second!=nullptr)
        {
            pair.first->FreeTable(stop);
        }
        std::cout<<pair.first->getTableNumber()<<" "<<pair.first->getTotalUsageTime().serialize()<<" "<<(pair.first->getTableHours())*CostPerHour<<std::endl;
    }
}

void Club::printEndTime()
{
    std::cout<<stop<<std::endl;
}
void Club::printStartTime()
{
     std::cout<<start<<std::endl;
}