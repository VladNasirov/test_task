#pragma once
#include <iostream>

enum class ClientState
{
    None,
    Waiting,
    Playing
};

class Client
{
    public:
    std::string getName();
    void setName(std::string n);

    ClientState getClientState();
    void setClientState(ClientState st);

    Client();
    Client(std::string name);
    private:
    std::string name;
    ClientState state;
};