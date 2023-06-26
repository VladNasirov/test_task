#include "Event.h"
void Event::StringToEvent(std:: string st)//TODO проверку на корректность body
{
        std::string line;
        std::istringstream iss(st);
        iss >> eventTime;
        iss.ignore(); // Ignore the space character
        iss>>line;
        int number = std::stoi(line);
        if((number>0&&number<=4)||(number>=11&&number<=13))
        {
            eventId=number;
        }
        else
        { //if event not in the pull
            std::cout<<"Wrong number on "<<st<<"!"<<std::endl;
            exit(0);
        }
        iss.ignore();
        iss>>clientName;
        if(eventId==2)
        {
            iss>>clientEvent;
        }
        
}
unsigned int Event::getEventId()
{
        return eventId;
}

void Event::printEvent()
{
    if(eventId==2||eventId==12)
    {
        std::cout<<eventTime<<" "<<eventId<<" "<<clientName<<" "<<clientEvent<<std::endl;
    }
    else
    {
        std::cout<<eventTime<<" "<<eventId<<" "<<clientName<<std::endl;
    }
}

ClubTime Event::getTime()
{
    return eventTime;
}
unsigned int Event::getClientEvent()
{
    return clientEvent;
}
std::string Event::getClientName()
{
    return clientName;
}

Event::Event(OutgoingEvent e,ClubTime c, std::string n, unsigned int t)
{
    eventId=(unsigned int)e;//static cast
    eventTime=c;
    clientName=n;
    clientEvent=t;
}
 Event::Event(OutgoingEvent e,ClubTime c, std::string n)
 {
     eventId=(unsigned int)e;
     eventTime=c;
     body=n;
 }