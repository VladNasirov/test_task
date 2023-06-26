#pragma once
#include <iostream>
#include "Club.h"
#include "File.h"

class EventReader
{
    public:
    void ReadFile();
    void HandleEvent(Event& ev);
    void HandleIncomingEvent(IncomingEvent incEv, Event& ev);
    void HandleOutgoingEvent(OutgoingEvent outEv, Event& ev, const char* ErrorText);
    private:
    Club computerClub;
    File file;
};