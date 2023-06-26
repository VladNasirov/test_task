#pragma once
#include <iostream>
#include <fstream>

#include "Event.h"
class File
{
    public:
    int ReadTables();
    std::string ReadClubTimeString();
    int ReadCostPerHour();
    Event ReadEvent();
    bool endFile();
    void setFilePATH(const std::string path)
    {
        PATH=path;
    }
    private:
    std::string PATH = "test_file.txt";
    std::streampos pos;
    ClubTime lastEventTime;
};

