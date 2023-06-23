#include "File.h"
//TODO дописать логику файлов
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
        }

    }
    else
    {
        std::cout<<"Can`t open file!!"<<std::endl;
        exit(0);
    }
}
ClubTime File::ReadClubTimeOpen()
{
    std::ifstream inputFile(PATH);
    std::string line;
    ClubTime ct;
    if(inputFile.is_open())
    {
        inputFile.seekg(pos);
         // Считываем строку до первого пробела
        if (std::getline(inputFile, line, ' ')) {
            try {
             pos = inputFile.tellg();//save pos
             ct.deserialize(line);
             return ct;
            } 
            catch (const std::exception&) 
            {
                std::cout<<"The "<<line<<" has invalid format!"<<std::endl;
                exit(-1);
            }
        } else {
            std::cout<<"The "<<line<<" has invalid format!"<<std::endl;
            exit(-1);
        }

    }
    else
    {
        std::cout<<"Can`t open file!!"<<std::endl;
        exit(0);
    }
}
ClubTime File::ReadClubTimeClose()
{
    std::ifstream inputFile(PATH);
    std::string line;
    ClubTime ct;
    if(inputFile.is_open())
    {
        inputFile.seekg(pos);
         // Считываем одну строку из файла
         
         // Считываем строку до первого пробела
        if (std::getline(inputFile, line, ' ')) {
            try {
             pos = inputFile.tellg();//save pos
             ct.deserialize(line);
             return ct;
            } 
            catch (const std::exception&) 
            {
                std::cout<<"The "<<line<<" has invalid format!"<<std::endl;
                exit(-1);
            }
        } else {
            std::cout<<"The "<<line<<" has invalid format!"<<std::endl;
            exit(-1);
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
            ev.StringToEvent(line);
            pos = inputFile.tellg();//save pos
            return ev;
            } 
            catch (const std::exception&) 
            {
                std::cout<<"The "<<line<<" has invalid format!"<<std::endl;
                exit(-1);
            }
        } else {
            std::cout << "Can`t read the line!" << std::endl;
        }

    }
    else
    {
        std::cout<<"Can`t open file!!"<<std::endl;
        exit(0);
    }
}