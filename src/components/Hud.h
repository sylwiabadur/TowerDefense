#ifndef UNTITLED5_HUD_H
#define UNTITLED5_HUD_H
#include <SFML/Graphics.hpp>
#include "../managers/ViewManager.h"
#include "../managers/GameManager.h"
#include "../managers/AssetsManager.h"
#include "../components/Button.h"
#include <string.h>

class Hud
{
    std::vector<sf::Text *> texts;
    std::vector<Button*>buttons;

  public:
    Hud();
    void render(sf::RenderWindow *window);
    void handleEvent(sf::Event *e);
    bool letUpgrade();
};

#endif //UNTITLED5_HUD_H