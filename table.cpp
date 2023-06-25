#include "table.h"

TableState Table::getTableState()
{
    return ts;
}
void Table::setTableState(TableState state)
{
    ts=state;
}

Table::Table(unsigned int n)
{
    number=n;
    ts=TableState::Empty;
}

void Table::FreeTable()
{
    //TODO delete client
    setTableState(TableState::Empty);
}

unsigned int Table::getTableNumber()
{
    return number;
}