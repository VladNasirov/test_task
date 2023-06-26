#include <sstream>
#include <iomanip>
#include "ClubTime.h"

std::string ClubTime::serialize() const {
        std::ostringstream oss;
        oss << std::setfill('0') << std::setw(2) << hours << ":"
            << std::setfill('0') << std::setw(2) << minutes;
        return oss.str();
}

void ClubTime::deserialize(const std::string& serializedTime) {
        std::istringstream iss(serializedTime);
        char delimiter;
        iss >> hours >> delimiter >> minutes;
}

// Оператор перегрузки для вывода времени в поток
std::ostream& operator<<(std::ostream& os, const ClubTime& time) {
    os << std::setfill('0') << std::setw(2) << time.hours << ":"
       << std::setfill('0') << std::setw(2) << time.minutes;
    return os;
}

// Оператор перегрузки для чтения времени из потока
std::istream& operator>>(std::istream& is, ClubTime& time) {
    char delimiter;
    is >> time.hours >> delimiter >> time.minutes;
    if(time.hours>23||time.hours<0||time.minutes>59||time.minutes<0)
    {
        std::cout<<"Wrong time format!"<<std::endl;
        exit(-1);
    }
    return is;
}

 unsigned int ClubTime::getHours()
 {
    return hours;
 }
unsigned int ClubTime::getMinutes()
{
    return minutes;
}

 ClubTime::ClubTime(unsigned int hours, unsigned int minutes)
 {
   this->hours=hours;
   this->minutes=minutes;
 }
  ClubTime::ClubTime()
 {
   this->hours=0;
   this->minutes=0;
 }