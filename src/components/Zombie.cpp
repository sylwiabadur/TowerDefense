#include "Zombie.h"

Zombie::Zombie()
{
    int dy = rand() % 40 - 20;
    position.x = GameManager::get().width;
    position.y = 390 + dy;
    velocity = 1.;
    shealth = 4; //obrona
    dmg = 2;     //atak

    improveZombie();

    ehealth = shealth;
    pic.setTexture(*AssetsManager::get().getTexture("zombie.png"), true);
    pic.setPosition(position);

    dmgI.setSize(sf::Vector2f(40, 4));
    dmgI.setOutlineColor(sf::Color(255, 255, 255));
    dmgI.setFillColor(sf::Color(255, 255, 255));
    dmgI.setOutlineThickness(2);

    dmgII.setSize(sf::Vector2f(40 * ehealth / shealth, 4));
    dmgII.setFillColor(sf::Color(0, 255, 0));
}
Zombie::~Zombie()
{
    int r = rand() % 6;
    std::stringstream s;
    s << "zombie_scream_" << r << ".wav";
    SoundManager::get().playSound(s.str());
}
void Zombie::render(sf::RenderWindow *window)
{
    position.x -= (float)velocity;
    pic.setPosition(position);
    dmgI.setPosition(position.x + 30, position.y - 30);
    dmgII.setPosition(position.x + 30.5, position.y - 29.5);
    dmgII.setSize(sf::Vector2f(40 * ehealth / shealth, 4));
    window->draw(pic);
    window->draw(dmgI);
    window->draw(dmgII);
}

sf::Vector2f Zombie::getPosition()
{
    return position;
}

int Zombie::getHealth()
{
    return ehealth;
}
void Zombie::lowerHealth()
{
    if (ehealth > 0)
    {
        ehealth--;
    }
}
int Zombie::getDamage()
{
    return dmg;
}
int Zombie::improveZombie()
{
    shealth += GameManager::get().counter / 20;
    dmg += GameManager::get().counter / 30;
    velocity += GameManager::get().counter / 30;
}