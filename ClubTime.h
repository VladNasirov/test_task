#pragma once
#include <iostream>


class ClubTime
{
    public:
    std::string serialize() const;
    std::ostream& operator<<(std::ostream& os, const ClubTime& time);
    void deserialize(const std::string& serializedTime);
    std::istream& operator>>(std::istream& is, ClubTime& time) {
    private:
    int hours;
    int minutes;
};