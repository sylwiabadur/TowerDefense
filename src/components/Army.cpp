#include "Army.h"
#include <math.h>
#include <sstream>

Army::Army()
{
    clock = new sf::Clock;
    clock->restart();
    zombies.push_back(new Zombie());
}

void Army::render(sf::RenderWindow *window)
{

    if (clock->getElapsedTime().asMilliseconds() >= GameManager::get().getInterval())
    {
        clock->restart();
        zombies.push_back(new Zombie());
    }
    for (auto z : zombies)
    {
        z->render(window);
    }
}

void Army::handleEvent(sf::Event *e)
{
}

std::vector<Zombie *> *Army::getZombies()
{
    return &zombies;
}