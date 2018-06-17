#ifndef UNTITLED5_GAME_H
#define UNTITLED5_GAME_H
#include "../prototypes/View.h"
#include <SFML/Graphics.hpp>
#include "../managers/ViewManager.h"
#include "../managers/GameManager.h"
#include "../managers/CollisionManager.h"
#include "../managers/AssetsManager.h"
#include "../managers/SoundManager.h"
#include "../components/Cannon.h"
#include "../components/Zombie.h"
#include "../components/Army.h"
#include "../components/Hud.h"
class Game : public View
{
  sf::RectangleShape *rect;
  sf::RectangleShape *tower;
  std::vector<sf::Sprite> staticSprite;

  sf::Sprite getPic(std::string path);

public:
  Game();
  ~Game();
  void render(sf::RenderWindow *window);
  void handleEvent(sf::Event *e);
  void init();

  //Lifecycle
  void onDestroy();

  Cannon *cann;
  Army *army;
  Hud *hud;
};

#endif //UNTITLED5_GAME_H