#ifndef UNTITLED5_SCORE_H
#define UNTITLED5_SCORE_H
#include "../prototypes/View.h"
#include <SFML/Graphics.hpp>
#include "../managers/ViewManager.h"
#include "../managers/GameManager.h"
#include "../components/Button.h"
#include "../components/Scoreboard.h"
class Score : public View
{
  sf::Sprite pic;
  std::vector<Button *> buttons;

public:
  Score();
  ~Score();
  void render(sf::RenderWindow *window);
  void handleEvent(sf::Event *e);
  void init();
  Scoreboard *sboard;
};

#endif //UNTITLED5_SCORE_H