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
    void FreeTable();
    Table(unsigned int n);
    TableState getTableState();
    void setTableState(TableState state);

    unsigned int getTableNumber();
    

    private:
    unsigned int number;
    TableState ts;
    ClubTime TableUsageTime;
};