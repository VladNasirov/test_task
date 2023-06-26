#pragma once
#include <iostream>


class ClubTime
{
    public:
    std::string serialize() const;
    friend std::ostream& operator<<(std::ostream& os, const ClubTime& time);
    void deserialize(const std::string& serializedTime);
    friend std::istream& operator>>(std::istream& is, ClubTime& time);
    int getHours();
    int getMinutes();
    ClubTime(int hours, int minutes);
    ClubTime()=default;
    ClubTime operator+(const ClubTime& other) const {
        int totalMinutes = minutes + other.minutes;
        int carry = totalMinutes / 60;
        int finalMinutes = totalMinutes % 60;
        int finalHours = hours + other.hours + carry;
        return ClubTime(finalHours, finalMinutes);
    }

    ClubTime operator-(const ClubTime& other) const {
        int totalMinutes = hours * 60 + minutes - (other.hours * 60 + other.minutes);
        int finalHours = totalMinutes / 60;
        int finalMinutes = totalMinutes % 60;
        return ClubTime(finalHours, finalMinutes);
    }
    private:
    int hours;
    int minutes;
};