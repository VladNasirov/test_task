#include "EventReader.h"

void EventReader::HandleIncomingEvent(IncomingEvent incEv, Event& ev)
{
    try
    {
        switch(incEv)
        {
            case IncomingEvent::ClientHere:
            {
                //Вывод информации о клиенте
                ev.printEvent();
                //Проверка есть ли он в клубе уже генерируется ошибка YouShallNotPass
                if(computerClub.alreadyInTheClub(ev.getClientName()))
                {
                    throw("YouShallNotPass");//YouShallNotPass
                }
                //Проверка прихода в нерабочие часы генерируется ошибка NotOpenYet
                if(!computerClub.isOpen(ev.getTime()))
                {
                    throw("NotOpenYet");//NotOpenYet
                }
                //Создание клиента
                std::shared_ptr<Client> c=std::make_shared<Client>(ev.getClientName());
                computerClub.addToList(c);
                if(!computerClub.hasFreeTables())
                {
                    computerClub.addToQue(c);
                }
                break;
            }
            case IncomingEvent::ClientAtTheTable:
            {
                //Вывод информации об ивенте
                ev.printEvent();
                // Если клиент не находится в компьютерном клубе, генерируется ошибка ClientUnknown.
                if(!computerClub.alreadyInTheClub(ev.getClientName()))
                {
                    throw("ClientUnknown");//ClientUnknown
                }
                auto client=computerClub.getClientFromList(ev.getClientName());
                 //Смена стола
                 if(client->getClientState()==ClientState::Playing)
                 {
                    computerClub.changeTable(client, ev.getClientEvent());
                 }
                 else
                 {
                    //Занят ли стол и попытка пересесть на свой стол генерируется ошибка PlaceIsBusy.
                    computerClub.takeTable(ev.getClientEvent(), client);
                 }
               break;
            }
            case IncomingEvent::ClientWaiting:
            {
                //Вывод информации об ивенте
                ev.printEvent();
                
                //Если в клубе есть свободные столы, то генерируется ошибка ICanWaitNoLonger! может больше не ждать
                if(computerClub.hasFreeTables())
                {
                    throw("ICanWaitNoLonger!");//ICanWaitNoLonger!
                }
                //Если очередь больше, чем число столов, то клиент уходит и генерирует OutgoingEvent::ClientLeaves
                if(computerClub.queueTooBig())
                {
                    HandleOutgoingEvent(OutgoingEvent::ClientLeaves, ev, "");
                }
                break;
            }
            case IncomingEvent::ClientLeaves:
            {
                //Вывод информации об ивенте
                ev.printEvent();
                //Если клиент не находится в компьютерном клубе, генерируется ошибка ClientUnknown.
                if(!computerClub.alreadyInTheClub(ev.getClientName()))
                {
                    throw("ClientUnknown");//ClientUnknown
                }
                //Когда клиент уходит, стол, за которым он сидел освобождается и его занимает первый клиент из очереди ожидания OutgoingEvent::ClientTookTheTable
                computerClub.clientLeaves(ev.getClientName());
                HandleOutgoingEvent(OutgoingEvent::ClientTookTheTable, ev, "");
                break;
            }
        }
    }
    catch(const char* ErrorText)
    {
        HandleOutgoingEvent(OutgoingEvent::Error, ev, ErrorText);
    }
}


void EventReader::HandleOutgoingEvent(OutgoingEvent outEv, Event& ev, const char* ErrorText)
{
    switch(outEv)
    {
        case OutgoingEvent::ClientLeaves://TODO
        {
            //Вывод информации о клиенте
            Event e(OutgoingEvent::ClientLeaves, computerClub.getNow(), ev.getClientName());
            e.printEvent();
            //Генерируется в конце рабочего дня для всех клиентов, оставшихся в компьютерном клубе, в алфавитном порядке их имен. А также, когда клиент встает в очередь, а очередь ожидания уже заполнена.
            //computerClub.printProfit();//TODO
            break;
        }
        case OutgoingEvent::ClientTookTheTable://Клиент из очереди
        {
            //Вывод информации об ивенте
            if(!computerClub.queIsEmpty())
            {
            auto clientName=computerClub.getNextClient()->getName();
            unsigned int place=computerClub.getFreeTable();
            Event e(OutgoingEvent::ClientTookTheTable, ev.getTime(), clientName, place);
            e.printEvent();//Будет отличаться, т.к. не совсем body
            //Генерируется для первого клиента в очереди при освобождении любого стола.
            auto client=computerClub.getClientFromList(clientName);
            computerClub.takeTable(place, client);
            }
            break;
        }
        case OutgoingEvent::Error:
        {
            std::cout<<ev.getTime()<<" "<<(unsigned int)OutgoingEvent::Error<<" "<<ErrorText<<std::endl;
            break;
        }
        
    }
}


void EventReader::HandleEvent(Event& ev)
{
    switch(ev.getEventId())
    {
        case 0:
        {
            //TODO none type enum
            break;
        }
        case 1:
        {
            HandleIncomingEvent(IncomingEvent::ClientHere, ev);
            break;
        }
        case 2:
        {
            HandleIncomingEvent(IncomingEvent::ClientAtTheTable, ev);
            break;
        }
        case 3:
        {
            HandleIncomingEvent(IncomingEvent::ClientWaiting, ev);
            break;
        }
        case 4:
        {
            HandleIncomingEvent(IncomingEvent::ClientLeaves, ev);
            break;
        }
    }
}
void EventReader::ReadFile()
{
    computerClub.setNumberOfTables(file.ReadTables());
    computerClub.setTime(file.ReadClubTimeString());
    computerClub.setCostPerHour(file.ReadCostPerHour());
    computerClub.printStartTime();
    while(!file.endFile())
    {
        Event ev=file.ReadEvent();
        HandleEvent(ev);
    }    
    computerClub.printEndTime();
    //computerClub.printProfit();
}