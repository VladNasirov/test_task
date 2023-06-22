#pragma once
#include <iostream>
#include "Club.h"
#include "File.h"
enum class IncomingEvent
{
    None,
    ClientHere=1,
    ClientAtTheTable=2,
    ClientWaiting=3,
    ClientLeaves=4
};
enum class OutgoingEvent
{
    None,
    ClientLeaves=11,
    ClientTookTheTable=12,
    Error=13
};


class EventReader
{
    public:
    void ReadFile();
    void HandleEvent(Event& ev);
    bool HandleIncomingEvent(IncomingEvent incEv, Event& ev);
    bool HandleOutgoingEvent(OutgoingEvent outEv, Event& ev);
    private:
    Club computerClub;
    File file;
};