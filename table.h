#pragma once
#include <iostream>
#include "client.h"
enum class TableState
{
    Empty,
    Occupied
};

class Table
{
    public:
    void OccupyTable(Client& c);
    void FreeTable();
    Table(unsigned int n);
    TableState getTableState();
    void setTableState(TableState state);

    private:
    unsigned int number;
    TableState ts;
    Client client;
};