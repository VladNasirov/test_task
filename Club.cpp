#pragma once
#include "Club.h"
void Club::setNumberOfTables(unsigned int num)
{
    NumberOfTables=num;
    for(int i=0; i<NumberOfTables; i++)
    {
        Table tb(i);
        Client c;
        tables.push_back(tb, c);
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

void Club::addToQue(Client& c)
{
    clients.push(c);
}


bool Club::alreadyInTheClub(std::string name)
{
    for(int i=0; i<tables.size(); i++)//проверка занятых компьютеров
    {
        if(tables[i].second.getName()==name)
        {
            //TODO YOUSHALL NOT PASS
            return true;
        }
    }
    if (clients.empty()) 
    {
        std::cout << "Очередь пуста" << std::endl;
    } 
    else 
    {
        std::queue<Client> tempQueue = clients; // Создаем временную копию очереди
        while (!tempQueue.empty()) {
            Client& client = tempQueue.front(); // Получаем ссылку на текущего клиента
            if (client.getName() == name) 
            {
                return true; // Клиент с заданным именем найден
            }
            tempQueue.pop(); // Удаляем текущего клиента из временной очереди
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
        if(tables[i].first.getTableState()==TableState::Empty)
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