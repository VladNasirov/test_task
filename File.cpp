#include "File.h"
int File::ReadTables()
{
    std::ifstream inputFile(PATH);
    std::string line;
    if(inputFile.is_open())
    {
         // Считываем одну строку из файла
         
        if (std::getline(inputFile, line)) {
        try {
            int number = std::stoi(line);
            pos = inputFile.tellg();//save pos
            inputFile.close();
            return number;
            } 
            catch (const std::exception&) 
            {
                std::cout<<"The "<<line<<" has invalid format!"<<std::endl;
                exit(-1);
            }
        } else {
            std::cout << "Can`t read the line!" << std::endl;
            exit(-1);
        }

    }
    else
    {
        std::cout<<"Can`t open file!!"<<std::endl;
        exit(0);
    }
}
std::string File::ReadClubTimeString()
{
    std::ifstream inputFile(PATH);
    std::string line;
    inputFile.seekg(pos);
    if(inputFile.is_open())
    {
    if (std::getline(inputFile, line)) {
        try {
            pos = inputFile.tellg();//save pos
            return line;
            } 
            catch (const std::exception&) 
            {
                std::cout<<"The "<<line<<" has invalid format!"<<std::endl;
                exit(-1);
            }
        }
    }
    else
    {
        std::cout<<"Can`t open file!!"<<std::endl;
        exit(0);
    }
}

int File::ReadCostPerHour()
{
    std::ifstream inputFile(PATH);
    std::string line;
    if(inputFile.is_open())
    {
         // Считываем одну строку из файла
          inputFile.seekg(pos);
        if (std::getline(inputFile, line)) {
        try {
            int number = std::stoi(line);
            pos = inputFile.tellg();//save pos
            return number;
            } 
            catch (const std::exception&) 
            {
                std::cout<<"The "<<line<<" has invalid format!"<<std::endl;
                exit(-1);
            }
        } else {
            std::cout << "Can`t read the line!" << std::endl;
            exit(-1);
        }

    }
    else
    {
        std::cout<<"Can`t open file!!"<<std::endl;
        exit(0);
    }
}

Event File::ReadEvent()
{
    Event ev;
    std::ifstream inputFile(PATH);
    std::string line;
    if(inputFile.is_open())
    {
         // Считываем одну строку из файла
          inputFile.seekg(pos);
        if (std::getline(inputFile, line)) {
        try {
            if(line.empty())
            {
                std::cout<<"Empty line!"<<std::endl;
                exit(0);
            }
            ev.StringToEvent(line);
            if(!(ev.getTime()>=lastEventTime))
            {
                std::cout<<"Wrong time on line: "<<line<<" !"<<std::endl;
                exit(-1);
            }
            pos = inputFile.tellg();//save pos
            lastEventTime=ev.getTime();
            return ev;
            } 
            catch (const std::exception&) 
            {
                std::cout<<"The "<<line<<" has invalid format!"<<std::endl;
                exit(-1);
            }
        }
        else
        {
            std::cout<<"Can`t read the line!"<<std::endl;
            exit(-1);
        }

    }
    else
    {
        std::cout<<"Can`t open file!!"<<std::endl;
        exit(0);
    }
}

 bool File::endFile()
 {
    std::ifstream inputFile(PATH);
    if(inputFile.is_open())
    {
        inputFile.seekg(pos);
        if(inputFile.eof()||pos==-1)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    else
    {
        std::cout<<"Can`t open file!!"<<std::endl;
        exit(0);
    }
 }