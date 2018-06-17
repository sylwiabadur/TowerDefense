#ifndef UNTITLED5_ZOMBIE_H
#define UNTITLED5_ZOMBIE_H
#include <SFML/Graphics.hpp>
#include "../managers/ViewManager.h"
#include "../managers/GameManager.h"
#include "../managers/AssetsManager.h"
#include "../managers/SoundManager.h"
#include <math.h>
#include <sstream>
#include <string>
class Zombie
{
    sf::Vector2f position;
    sf::Sprite pic;
    int dmg;
    int shealth; //start health
    int ehealth; //end health
    double velocity;
    sf::RectangleShape dmgI;
    sf::RectangleShape dmgII;
public:
  Zombie();
  ~Zombie();
  void render(sf::RenderWindow *window);
  sf::Vector2f getPosition();
  int getHealth();
  void lowerHealth();
  int getDamage();
  int improveZombie();
  void onDestroy();
};

#endif //UNTITLED5_ZOMBIE_H