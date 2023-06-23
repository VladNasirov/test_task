#pragma once
#include "EventReader.h"




bool EventReader::HandleIncomingEvent(IncomingEvent incEv, Event& ev)
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
                //YouShallNotPass
            }
            //Проверка прихода в нерабочие часы генерируется ошибка NotOpenYet
            if(!computerClub.isOpen(ev.getTime()))
            {
                //NotOpenYet
            }

            //Создание клиента
        }
        case IncomingEvent::ClientAtTheTable:
        {
            //Вывод информации об ивенте
            ev.printEvent();
            //Смена стола

            //Занят ли стол и попытка пересесть на свой стол генерируется ошибка PlaceIsBusy.
            // Если клиент не находится в компьютерном клубе, генерируется ошибка ClientUnknown.
            if(!computerClub.alreadyInTheClub(ev.getClientName()))
            {
                //ClientUnknown
            }
        }
        case IncomingEvent::ClientWaiting:
        {
            //Вывод информации об ивенте
            ev.printEvent();
            
            //Если в клубе есть свободные столы, то генерируется ошибка ICanWaitNoLonger! может больше не ждать
            if(computerClub.hasFreeTables())
            {
                //ICanWaitNoLonger!
            }
            //Если очередь больше, чем число столов, то клиент уходит и генерирует OutgoingEvent::ClientLeaves
            if(computerClub.queueTooBig())
            {
                HandleOutgoingEvent(OutgoingEvent::ClientLeaves, ev);
            }
        }
        case IncomingEvent::ClientLeaves:
        {
            //Вывод информации об ивенте
            ev.printEvent();
            //Если клиент не находится в компьютерном клубе, генерируется ошибка ClientUnknown.
            if(!computerClub.alreadyInTheClub(ev.getClientName()))
            {
                //ClientUnknown
            }
            //Когда клиент уходит, стол, за которым он сидел освобождается и его занимает первый клиент из очереди ожидания OutgoingEvent::ClientTookTheTable
            computerClub.clientLeaves(ev.getClientName());
            HandleOutgoingEvent(OutgoingEvent::ClientTookTheTable, ev);
        }
    }
}


bool EventReader::HandleOutgoingEvent(OutgoingEvent outEv, Event& ev)
{
      switch(outEv)
    {
        case OutgoingEvent::ClientLeaves:
        {
            //Вывод информации о клиенте
            ev.printEvent(); // не уверен, что надо
            //Генерируется в конце рабочего дня для всех клиентов, оставшихся в компьютерном клубе, в алфавитном порядке их имен. А также, когда клиент встает в очередь, а очередь ожидания уже заполнена.
        }
        case OutgoingEvent::ClientTookTheTable:
        {
            //Вывод информации об ивенте
            ev.printEvent();// не уверен, что надо
            //Генерируется для первого клиента в очереди при освобождении любого стола.
        }
        case OutgoingEvent::Error:
        {
            //Вывод ошибок, после возникновения
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

        case 11:
        {
            HandleOutgoingEvent(OutgoingEvent::ClientLeaves, ev);
            break;
        }
        case 12:
        {
            HandleOutgoingEvent(OutgoingEvent::ClientTookTheTable, ev);
            break;
        }
        case 13:
        {
             HandleOutgoingEvent(OutgoingEvent::Error, ev);
            break;
        }
    }
}
void EventReader::ReadFile()
{
    computerClub.setNumberOfTables(file.ReadTables());
    computerClub.setTime(file.ReadClubTimeOpen(), file.ReadClubTimeClose());
    computerClub.setCostPerHour(file.ReadCostPerHour());
    do
    {
        Event ev=file.ReadEvent();
        HandleEvent(ev);
        
    }while();
}