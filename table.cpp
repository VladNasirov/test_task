#include "table.h"

TableState Table::getTableState()
{
    return ts;
}
void Table::setTableState(TableState state)
{
    ts=state;
}



void Table::OccupyTable(Client& c)
{
    client=c;
    setTableState(TableState::Occupied);
}

void Table::FreeTable()
{
    //TODO delete client
    setTableState(TableState::Empty);
}
