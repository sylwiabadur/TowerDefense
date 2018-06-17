#ifndef UNTITLED5_SCOREBOARD_H
#define UNTITLED5_SCOREBOARD_H
#include <SFML/Graphics.hpp>
#include "../managers/ViewManager.h"
#include "../managers/GameManager.h"
#include "../managers/AssetsManager.h"
class Scoreboard
{
  sf::Text text;
  std::vector <statss> bests;

public:
  Scoreboard();
  void renderBoard(sf::RenderWindow *window);
};

#endif //UNTITLED5_SCOREBOARD_H