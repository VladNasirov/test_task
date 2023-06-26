#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
#include "ClubTime.h"
enum class IncomingEvent
{
    None,
    ClientHere=1,
    ClientAtTheTable=2,
    ClientWaiting=3,
    ClientLeaves=4
};
enum class OutgoingEvent
{
    None,
    ClientLeaves=11,
    ClientTookTheTable=12,
    Error=13
};

class Event
{
    public:
    void StringToEvent(std::string st);//TODO проверку на корректность body
    unsigned int getEventId();
    void printEvent();
    void parseBody();
    Event(OutgoingEvent e,ClubTime c, std::string n, unsigned int t);
    Event(OutgoingEvent e,ClubTime c, std::string n);
    Event()=default;
    std::string getClientName();
    ClubTime getTime();
    unsigned int getClientEvent();

    private:
    ClubTime eventTime;
    unsigned int eventId;
    std::string body;
    std::string clientName;
    unsigned int clientEvent;
};