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

void Table::FreeTable(ClubTime ct)
{
    setTableState(TableState::Empty);
    TableTotalUsageTime+=(ct-TableStart);
}
void Table::OccupyTable(ClubTime ct)
{
    setTableState(TableState::Occupied);
    TableStart=ct;
}
unsigned int Table::getTableNumber()
{
    return number;
}

unsigned int Table::getTableHours()
{
    unsigned int totalHours=0;
    totalHours+=TableTotalUsageTime.getHours();
    if(TableTotalUsageTime.getMinutes()>0)
    {
        totalHours++;
    }
    return totalHours;
}
ClubTime Table::getTotalUsageTime()
{
    return TableTotalUsageTime;
}