#pragma once
#include <iostream>
#include <fstream>

#include "Event.h"
class File
{
    public:
    int ReadTables();
    ClubTime ReadClubTimeOpen();
    ClubTime ReadClubTimeClose();
    int ReadCostPerHour();
    Event ReadEvent();
    private:
    const std::string PATH = "test_file.txt";
    std::streampos pos;
};

