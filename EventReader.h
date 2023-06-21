#pragma once
#include <iostream>
#include "Club.h"
enum class IncomingEvent
{
    ClientHere,
    ClientAtTheTable,
    ClientWaiting,
    ClientLeaves
};
enum class OutgoingEvent
{
    ClientLeaves,
    ClientTookTheTable,
    Error
};

class EventReader
{
    public:
    void ReadFile();
    bool HandleIncomingEvent(IncomingEvent incEv);
    bool HandleOutgoingEvent(OutgoingEvent outEv);
    private:
    Club computerClub;
};