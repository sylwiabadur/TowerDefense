#include "Menu.h"

Menu::Menu()
{
    name = "menu";
}
Menu::~Menu() {}
void Menu::render(sf::RenderWindow *window)
{
    window->draw(pic);
    buttons.at(0)->render();
    buttons.at(1)->render();
    buttons.at(2)->render();
}
void Menu::handleEvent(sf::Event *e)
{
    if (e->type == sf::Event::KeyPressed)
    {
        if (e->key.code == sf::Keyboard::Escape)
        {
            ViewManager::get().exit();
        }
    }
    buttons.at(0)->handleEvent(e);
    buttons.at(1)->handleEvent(e);
    buttons.at(2)->handleEvent(e);
}
void Menu::init()
{
    pic.setTexture(*AssetsManager::get().getTexture("menubg.png"), true);
    pic.setPosition(0, 0);
    Button *button = new Button(sf::Vector2f(100, 530));
    button->setTxt("Play");
    buttons.push_back(button);

    buttons.at(0)->onClick([]() {
        ViewManager::get().changeView("game");
    });

    Button *button1 = new Button(sf::Vector2f(300, 530));
    button1->setTxt("Exit");
    buttons.push_back(button1);

    buttons.at(1)->onClick([]() {
        ViewManager::get().exit();
    });
    Button *button2 = new Button(sf::Vector2f(500, 530));
    button2->setTxt("Score");
    buttons.push_back(button2);

    buttons.at(2)->onClick([]() {
        ViewManager::get().changeView("score");
    });
}