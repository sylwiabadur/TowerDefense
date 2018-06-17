#include "CollisionManager.h"
CollisionManager::CollisionManager() {}

void CollisionManager::ballCol(std::vector<Zombie *> *zombies, std::vector<Ball *> *balls)
{

    for (int i = 0; i < zombies->size(); i++)
    {
        for (int j = 0; j < balls->size(); j++)
        {
            int xz = zombies->at(i)->getPosition().x;
            int yz = zombies->at(i)->getPosition().y;
            int xb = balls->at(j)->getPosition().x;
            int yb = balls->at(j)->getPosition().y;
            if (xb >= (xz + 30) && xb <= (xz + 100) && yb >= (yz + 10) && yb <= (yz + 100))
            {

                balls->erase(balls->begin() + j);
                if (zombies->at(i)->getHealth() > 1)
                {
                    zombies->at(i)->lowerHealth();
                }
                else
                {
                    GameManager::get().counter++;
                    GameManager::get().score += (zombies->at(i)->getDamage());
                    GameManager::get().money += zombies->at(i)->getDamage();
                    delete zombies->at(i);
                    zombies->erase(zombies->begin() + i);
                    break;
                }
            }
        }
    }
}

void CollisionManager::towerCol(std::vector<Zombie *> *zombies)
{
    for (int i = 0; i < zombies->size(); i++)
    {
        int xz = zombies->at(i)->getPosition().x;
        int yz = zombies->at(i)->getPosition().y;
        if (xz <= 200)
        {
            zombies->erase(zombies->begin() + i);
            if ((GameManager::get().towerpoints - (zombies->at(i)->getDamage())) > 0)
            {
                GameManager::get().towerpoints = GameManager::get().towerpoints - (zombies->at(i)->getDamage());
            }
            else
            {
                ViewManager::get().changeView("score");
            }
        }
    }
}

CollisionManager &CollisionManager::get()
{
    static CollisionManager manager;
    return manager;
}