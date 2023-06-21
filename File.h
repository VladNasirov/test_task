#pragma once
#include <iostream>
#include "ClubTime.h"
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
};

