#include "Hud.h"
Hud::Hud()
{
    sf::Text *text = new sf::Text;
    text->setPosition(sf::Vector2f(300, 550));
    text->setFillColor(sf::Color(255, 255, 255));
    text->setCharacterSize(25);
    text->setOutlineThickness(2);
    text->setOutlineColor(sf::Color(0, 0, 0));
    text->setFont(*AssetsManager::get().getFont());
    texts.push_back(text);

    sf::Text *text1 = new sf::Text;
    text1->setPosition(sf::Vector2f(80, 550));
    text1->setFillColor(sf::Color(255, 255, 255));
    text1->setCharacterSize(25);
    text1->setOutlineThickness(2);
    text1->setOutlineColor(sf::Color(0, 0, 0));
    text1->setFont(*AssetsManager::get().getFont());
    texts.push_back(text1);

    sf::Text *text2 = new sf::Text;
    text2->setPosition(sf::Vector2f(550, 550));
    text2->setFillColor(sf::Color(255, 255, 255));
    text2->setCharacterSize(25);
    text2->setOutlineThickness(2);
    text2->setOutlineColor(sf::Color(0, 0, 0));
    text2->setFont(*AssetsManager::get().getFont());
    texts.push_back(text2);

    Button *button = new Button(sf::Vector2f(800, 530));
    button->setTxt("Upgrade");
    buttons.push_back(button);

    buttons.at(0)->onClick([this]() {
        if (letUpgrade())
        {
            GameManager::get().money -= 20;
            GameManager::get().towerpoints += 4;
        }
    });
}

void Hud::render(sf::RenderWindow *window)
{
    texts.at(0)->setString("Current score: " + std::to_string(GameManager::get().score));
    texts.at(1)->setString("Tower's health: " + std::to_string(GameManager::get().towerpoints));
    texts.at(2)->setString("Money: " + std::to_string(GameManager::get().money));
    window->draw(*texts.at(0));
    window->draw(*texts.at(1));
    window->draw(*texts.at(2));
    if (!letUpgrade())
    {
        buttons.at(0)->changeColor(sf::Color(170, 170, 170));
    }
    else
        buttons.at(0)->changeColor(sf::Color(247, 96, 119));
    buttons.at(0)->render();
}

void Hud::handleEvent(sf::Event *e)
{
    buttons.at(0)->handleEvent(e);
}

bool Hud::letUpgrade()
{
    return GameManager::get().money >= 20;
}