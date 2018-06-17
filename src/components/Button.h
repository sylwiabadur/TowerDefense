#ifndef UNTITLED5_SNAKE_H
#define UNTITLED5_SNAKE_H
#include <SFML/Graphics.hpp>
#include "../managers/ViewManager.h"
#include "../managers/AssetsManager.h"
#include <string>
#include <functional>
class Button
{
  int width;
  int height;
  int border;
  bool active;
  sf::RectangleShape rect;
  sf::Text text;
  std::function<void()> callback;
  sf::Vector2f position;

public:
  Button(sf::Vector2f pos);
  Button *onClick(std::function<void()>cb);
  Button *setTxt(std::string txt);
  void handleEvent(sf::Event *e);
  void render();
  void changeColor(sf::Color col);
};
#endif //UNTITLED5_SNAKE_H