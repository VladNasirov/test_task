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

    TableState getTableState();
    void setTableState(TableState state);

    private:
    int number;
    TableState ts;
    Client client;
};