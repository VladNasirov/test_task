#pragma once
#include <iostream>
#include "Club.h"
#include "File.h"

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