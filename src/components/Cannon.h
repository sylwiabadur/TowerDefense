#ifndef UNTITLED5_CANNON_H
#define UNTITLED5_CANNON_H
#include <SFML/Graphics.hpp>
#include "../managers/ViewManager.h"
#include "../managers/GameManager.h"
#include "../managers/AssetsManager.h"
#include <math.h>
#include "Ball.h"
#include <vector>
class Cannon
{
    sf::Vector2f position;
    double angle;
    sf::Sprite pic;
public:
  Cannon();
  void createBall();
  void render(sf::RenderWindow *window);
  void handleEvent(sf::Event *e);
  void garbageCollector();
  std::vector<Ball*> balls;
  std::vector <Ball*>*getBalls();
};

#endif //UNTITLED5_CANNON_H