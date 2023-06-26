#include "EventReader.h"

int main(int argc, char* argv[])
{
    std::string path=argv[1];
    EventReader er(path);
    er.ReadFile();
    return 0;
}