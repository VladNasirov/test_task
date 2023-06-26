#pragma once
#include <iostream>


class ClubTime
{
    public:
    std::string serialize() const;
    friend std::ostream& operator<<(std::ostream& os, const ClubTime& time);
    void deserialize(const std::string& serializedTime);
    friend std::istream& operator>>(std::istream& is, ClubTime& time);
    unsigned int getHours();
    unsigned int getMinutes();
    ClubTime(unsigned int hours, unsigned int minutes);
    ClubTime();
    ClubTime operator+(const ClubTime& other) const {
        unsigned int totalMinutes = minutes + other.minutes;
        unsigned int carry = totalMinutes / 60;
        unsigned int finalMinutes = totalMinutes % 60;
        unsigned int finalHours = hours + other.hours + carry;
        return ClubTime(finalHours, finalMinutes);
    }

    ClubTime operator-(const ClubTime& other) const {
        unsigned int totalMinutes = hours * 60 + minutes - (other.hours * 60 + other.minutes);
        unsigned int finalHours = totalMinutes / 60;
        unsigned int finalMinutes = totalMinutes % 60;
        return ClubTime(finalHours, finalMinutes);
    }
    bool operator>=(const ClubTime& other) const {
    if (hours > other.hours) {
        return true;
    } else if (hours == other.hours && minutes >= other.minutes) {
        return true;
    } else
    {
        return false;
    }
    }

    ClubTime& operator+=(const ClubTime& other) {
    minutes += other.minutes;
    hours += other.hours + minutes / 60;
    minutes %= 60;
    return *this;
    }

    private:
    unsigned int hours;
    unsigned int minutes;
};