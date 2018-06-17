#ifndef UNTITLED5_BALL_H
#define UNTITLED5_BALL_H
#include <SFML/Graphics.hpp>
#include "../managers/AssetsManager.h"


class Ball
{
  sf::Vector2f velocity;
  sf::Vector2f gravVelocity;
  sf::Vector2f position;
  sf::Sprite pic;
  double angle;
  int rotationVelocity;

public:
  Ball(double a, sf::Vector2f start);
  void render(sf::RenderWindow *window);
  sf::Vector2f getPosition();
};

#endif //UNTITLED5_BALL_H