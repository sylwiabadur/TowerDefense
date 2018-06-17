#include "Cannon.h"

Cannon::Cannon()
{
    position.x = 250;
    position.y = 240;
    angle = -60; // -60 maksymalny kat wychylenia w gore a 90 maksymalny kat wychylenia w dol

    pic.setTexture(*AssetsManager::get().getTexture("cannon.png"), true);
    pic.setPosition(position);
    pic.setOrigin(23, 39);
}
void Cannon::createBall()
{
    balls.push_back(new Ball(angle - 30, position));
}
void Cannon::garbageCollector()
{
    for (int i = 0; i < balls.size(); i++)
    {
        if (balls.at(i)->getPosition().y >= 500 || balls.at(i)->getPosition().x >= GameManager::get().width || balls.at(i)->getPosition().x < 0)
        {
            balls.erase(balls.begin() + i);
        }
    }
}
void Cannon::render(sf::RenderWindow *window)
{
    pic.setRotation(angle);

    window->draw(pic);
    for (auto b : balls)
    {
        b->render(window);
        garbageCollector();
    }
}

void Cannon::handleEvent(sf::Event *e)
{
    if (e->type == sf::Event::MouseMoved)
    {
        int x, y; //pozycja
        x = e->mouseMove.x;
        y = e->mouseMove.y;
        double preAngle = atan2(y - position.y, x - position.x) * 180 / M_PI + 30; //+30 bo kąt odchylenia lufy na png

        if (preAngle > -60 && preAngle < 100)
        {
            angle = preAngle;
        }
    }
    else if ((e->type == sf::Event::MouseButtonPressed) && (sf::Mouse::getPosition(*ViewManager::get().getWindow()).y) <= 530)
    {
        createBall();
    }
}

std::vector<Ball *> *Cannon::getBalls()
{
    return &balls;
}