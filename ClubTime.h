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
    private:
    int hours;
    int minutes;
};