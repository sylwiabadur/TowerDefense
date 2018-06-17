#include "Scoreboard.h"
#include <string.h>

Scoreboard::Scoreboard()
{
    text.setFillColor(sf::Color(166, 184, 193));
    text.setCharacterSize(25);
    text.setOutlineThickness(1.5);
    text.setOutlineColor(sf::Color(102, 103, 102));
    text.setFont(*AssetsManager::get().getFont());

    bests = GameManager::get().readSave();
}
void Scoreboard::renderBoard(sf::RenderWindow *window)
{
    int y=180;
    for(int i=0;i<bests.size();i++)
    {
        std::string login(bests.at(i).name);
        text.setString(login+": "+std::to_string(bests.at(i).score));
        text.setPosition(sf::Vector2f(390,y));
        y+=30;
        window->draw(text);
    }
}