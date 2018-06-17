#ifndef UNTITLED5_ARMY_H
#define UNTITLED5_ARMY_H
#include <SFML/Graphics.hpp>
#include "../managers/ViewManager.h"
#include "../managers/GameManager.h"
#include "../managers/AssetsManager.h"
#include "Zombie.h"
#include <vector>
class Army
{
  std::vector<Zombie *> zombies;
  sf::Clock *clock;

public:
  Army();
  void render(sf::RenderWindow *window);
  void handleEvent(sf::Event *e);
  std::vector<Zombie *> *getZombies();
};

#endif //UNTITLED5_ARMY_H