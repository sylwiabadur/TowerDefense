#include "Ball.h"
#include <math.h>
Ball::Ball(double a, sf::Vector2f start)
{
    velocity = sf::Vector2f(10,10);
    gravVelocity=sf::Vector2f(0,0);
    angle = a * M_PI / 180;

    double s = 40;
    position = sf::Vector2f(s * cos(angle) + start.x, s * sin(angle) + start.y);

    int initRotate = rand()%360;
    rotationVelocity = rand()%5;
    pic.rotate(initRotate);
    pic.setTexture(*AssetsManager::get().getTexture("bomb.png"), true);
    pic.setPosition(position);
    pic.setOrigin(12, 15);
}

void Ball::render(sf::RenderWindow *window)
{
    pic.rotate(rotationVelocity);
    sf::Vector2f moveVec = sf::Vector2f(velocity.x * cos(angle), velocity.y * sin(angle)+gravVelocity.y);
    gravVelocity.y+=0.1;
    position += moveVec;
    pic.setPosition(position);
    window->draw(pic);
}
sf::Vector2f Ball::getPosition()
{
    return position;
}