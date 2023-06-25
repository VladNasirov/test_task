#pragma once
#include "Club.h"
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
void Club::setTime(ClubTime Start, ClubTime Stop)
{
    start=Start;
    stop=Stop;
}
void Club::setCostPerHour(unsigned int cost)
{
    CostPerHour=cost;
}

void Club::addToQue(std::shared_ptr<Client> c)
{
    clients.push(c);
}


bool Club::alreadyInTheClub(std::string name)//TODO просто в клубе
{
    for(int i=0; i<tables.size(); i++)//проверка занятых компьютеров
    {
        if(tables[i].second->getName()==name)
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

  void Club::takeTable(int tableNumber, std::shared_ptr<Client> c)
  {
    for(int i=0; i<tables.size(); i++)
    {
        if(tables[i].first->getTableNumber()==tableNumber&&tables[i].first->getTableState()==TableState::Empty)
        {
            tables[i].second->setName(c->getName());
            tables[i].second->setClientState(ClientState::Playing);
            tables[i].first->setTableState(TableState::Occupied);
            return;
        }
        else if(tables[i].first->getTableNumber()==tableNumber&&tables[i].first->getTableState()==TableState::Occupied)
        {
            throw("PlaceIsBusy");
        }
    }

  }

  void Club::clientLeaves(std::string name)//TODO удаление из клуба, подсчет выручки
  {
    //Освобождение стола
   for (auto& pair : tables) {
     if (pair.second->getName() == name) {
        pair.second.reset();
        pair.first->setTableState(TableState::Empty);
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