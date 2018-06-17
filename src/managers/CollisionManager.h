#ifndef UNTITLED5_COLLISIONMANAGER_H
#define UNTITLED5_COLLISIONMANAGER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../components/Army.h"
#include "../components/Ball.h"
#include "../managers/GameManager.h"

class CollisionManager{
    
    public:
    CollisionManager();
    static CollisionManager &get();
    void ballCol(std::vector <Zombie*> *zombies, std::vector<Ball*> *balls);
    void towerCol(std::vector<Zombie *> *zombies);
};

#endif //UNTITLED5_COLLISIONMANAGER_H