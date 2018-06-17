#ifndef UNTITLED5_GAMEMANAGER_H
#define UNTITLED5_GAMEMANAGER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

struct statss
{
    int score;
    char name[100];
};
class GameManager
{
    std::vector<statss> bestScore;

  public:
    int height;
    int width;
    int interval;
    int score;
    int towerpoints;
    int money;
    int counter; //counts dead zombies
    GameManager();
    int getInterval();

    std::vector<statss> readSave();
    void writeSave(std::vector<statss> statsss);
    std::string getRandomLogin();

    void collectData();

    static GameManager &get();
};

#endif //UNTITLED5_GAMEMANAGER_H