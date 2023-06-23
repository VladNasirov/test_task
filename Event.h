#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
#include "ClubTime.h"
class Event
{
    public:
    void StringToEvent(std::string st);//TODO проверку на корректность body
    unsigned int getEventId();
    void printEvent();
    void parseBody();

    std::string getClientName();
    ClubTime getTime();


    private:
    ClubTime eventTime;
    unsigned int eventId;
    std::string body;
    std::string clientName;
    std::string clientEvent;
};