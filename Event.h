#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
#include "ClubTime.h"
class Event
{
    public:
    void StringToEvent(std:: string st);//TODO проверку на корректность body
    unsigned int getEventId();
    void printEvent();
    private:
    ClubTime eventTime;
    unsigned int eventId;
    std::string body;
};