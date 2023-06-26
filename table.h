#pragma once
#include <iostream>
#include "client.h"
#include "ClubTime.h"
enum class TableState
{
    Empty,
    Occupied
};

class Table
{
    public:
    void FreeTable(ClubTime ct);
    void OccupyTable(ClubTime ct);
    Table(unsigned int n);
    TableState getTableState();
    void setTableState(TableState state);
    unsigned int getTableHours();
    unsigned int getTableNumber();
    ClubTime getTotalUsageTime();

    private:
    unsigned int number;
    TableState ts;
    ClubTime TableTotalUsageTime;
    ClubTime TableStart;
    ClubTime TableStop;
};