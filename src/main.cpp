#include <sstream>
#include <iostream>
#include <fstream>

#include "flytoelephant.h"

#if 1

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        std::cout << "Передано недостаточное количество аргументов" << std::endl;
        return 1;
    }

    std::ifstream worldFile(argv[1]);
    std::ifstream dictFile(argv[2]);

    std::string initWorld = "";
    std::string endWorld = "";

    std::getline(worldFile, initWorld);
    std::getline(worldFile, endWorld);

    std::vector<std::string> dictWorld;
    std::string line;

    while (std::getline(dictFile, line))
    {
        dictWorld.push_back(line);
    }
/*
    const int length = initWorld.length();
    std::ofstream oworldFile(argv[3]);
    for(std::string l : dictWorld)
    {
        if(l.length() == length)
        {
            oworldFile << l <<std::endl;
        }
    }

*/
    FlyToElephant* el = new FlyToElephant(initWorld, endWorld, dictWorld);
    // словарь слов больше не нужен, очищаем, чтобы память не занимал
    dictWorld.clear();

    auto result =  el->Execute();
    for(const std::string& s : result)
    {
        std::cout << s <<std::endl;
    }

    delete el;
    el = nullptr;
    return 0;
}

#endif
