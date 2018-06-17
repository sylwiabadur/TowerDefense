#include "GameManager.h"
#include <math.h>
#include <fstream>
#include <ctime>
#include <string.h>
GameManager::GameManager()
{
    height = 600;
    width = 1024;
    interval = 1000;
    score = 0;
    towerpoints = 10;
    counter = 0;
    money = 0;
}

GameManager &GameManager::get()
{
    static GameManager manager;
    return manager;
}
int GameManager::getInterval()
{
    return rand() % 1000 + interval;
}

std::vector<statss> GameManager::readSave()
{
    std::vector<statss> v;
    std::ifstream input("savedscore", std::ios::binary);
    if (input.good())
    {
        statss s;
        input.read((char *)&s, sizeof(statss));
        while (input.gcount() > 0)
        {
            v.push_back(s);
            input.read((char *)&s, sizeof(statss));
        }
    }
    input.close();
    bestScore = v;
    return v;
}
void GameManager::writeSave(std::vector<statss> statsss)
{
    std::ofstream input("savedscore", std::ios::binary | std::ios::trunc);
    if (input.good())
    {
        for (auto s : statsss)
        {
            input.write((char *)&s, sizeof(statss));
        }
    }
    input.close();
}

void GameManager::collectData()
{
    readSave();
    statss s;
    strcpy(s.name, getRandomLogin().c_str());
    s.score = GameManager::get().score;
    bestScore.push_back(s);
    sort(bestScore.begin(), bestScore.end(), [](const statss s1, const statss s2) {
        return s1.score > s2.score;
    });
    if (bestScore.size() > 5)
        bestScore.erase(bestScore.begin() + 5, bestScore.end());
    writeSave(bestScore);
}
std::string GameManager::getRandomLogin()
{
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "Player%d%m%I%M", timeinfo);
    std::string str(buffer);

    return str;
}