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
    std::cout<<eventTime<<" "<<eventId<<" "<<body;
}

ClubTime Event::getTime()
{
    return eventTime;
}