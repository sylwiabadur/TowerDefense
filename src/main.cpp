#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include "./managers/ViewManager.h"
#include "./managers/GameManager.h"
#include "./managers/AssetsManager.h"
#include "./prototypes/View.h"
#include "./views/Menu.h"
#include "./views/Game.h"
#include "./views/Score.h"
using namespace std;
int main()
{
    srand(time(NULL));
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(GameManager::get().width, GameManager::get().height), "Tower defence");
    View *menu = new Menu();
    View *game = new Game();
    View *score = new Score();

    window->setFramerateLimit(60);
    //Init singleton manager => load all assets
    AssetsManager::get();
    ViewManager::get().addView(menu);
    ViewManager::get().addView(game);
    ViewManager::get().addView(score);
    ViewManager::get().assignWindow(window);
    ViewManager::get().changeView("menu");

    while (!ViewManager::get().quit)
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            ViewManager::get().handleEvent(&event);

            if (event.type == sf::Event::Closed)
                window->close();
        }
        ViewManager::get().renderView();
    }
    return EXIT_SUCCESS;
}