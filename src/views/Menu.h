#ifndef UNTITLED5_MENU_H
#define UNTITLED5_MENU_H
#include "../prototypes/View.h"
#include <SFML/Graphics.hpp>
#include "../managers/ViewManager.h"
#include "../managers/GameManager.h"
#include "../managers/AssetsManager.h"
#include "../components/Button.h"
#include <iostream>
#include <string>

class Menu : public View
{
    sf::Sprite pic;
    std::vector<Button*>buttons;

  public:
    Menu();
    ~Menu();
    void render(sf::RenderWindow *window);
    void handleEvent(sf::Event *e);
    void init();
};

#endif //UNTITLED5_MENU_H