#include "client.h"

std::string Client::getName()
{
    return name;
}
void Client::setName(std::string n)
{
    name=n;
}

ClientState Client::getClientState()
{
    return state;
}
void Client::setClientState(ClientState st)
{
    state=st;
}

Client::Client()
{
    name="";
    state=ClientState::None;
}

Client::Client(std::string name)
{
    this->name=name;
}