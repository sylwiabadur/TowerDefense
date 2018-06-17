#include "Game.h"
Game::Game()
{
    name = "game";
}
Game::~Game()
{
}
void Game::render(sf::RenderWindow *window)
{
    CollisionManager::get().ballCol(army->getZombies(), cann->getBalls());
    CollisionManager::get().towerCol(army->getZombies());
    window->draw(staticSprite.at(0));
    window->draw(staticSprite.at(2));
    army->render(window);
    cann->render(window);
    window->draw(staticSprite.at(1));
    hud->render(window);
}
void Game::handleEvent(sf::Event *e)
{
    if (e->type == sf::Event::KeyPressed)
    {
        if (e->key.code == sf::Keyboard::Escape)
        {
            ViewManager::get().exit();
        }
        if (e->key.code == sf::Keyboard::Space)
        {
            ViewManager::get().changeView("score");
        }
    }
    cann->handleEvent(e);
    hud->handleEvent(e);
}
void Game::init()
{
    SoundManager::get().playMusic("music.wav");
    staticSprite.clear();

    staticSprite.push_back(getPic("BG.png"));
    staticSprite.push_back(getPic("FG.png"));
    staticSprite.push_back(getPic("tower.png"));
    staticSprite.at(2).setPosition(40, 245);

    cann = new Cannon();
    army = new Army();
    hud = new Hud();
}

void Game::onDestroy()
{
    SoundManager::get().stopMusic();
    GameManager::get().collectData();
    GameManager::get().score = 0;
    GameManager::get().towerpoints = 10;
    GameManager::get().money = 0;
    GameManager::get().counter = 0;
}

sf::Sprite Game::getPic(std::string path)
{
    sf::Sprite pic;
    pic.setTexture(*AssetsManager::get().getTexture(path), true);
    pic.setPosition(0, 0);
    return pic;
}