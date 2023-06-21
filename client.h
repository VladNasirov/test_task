#pragma once
#include <iostream>

enum class ClientState
{
    Waiting,
    Playing
};

class Client
{
    public:
    std::string getName();
    void setName();

    ClientState getClientState();
    void setClientState(ClientState st);

    private:
    std::string name;
    ClientState state;
};