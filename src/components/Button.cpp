#include "Button.h"

Button::Button(sf::Vector2f pos)
{
  position = pos;
  width = 150;
  height = 60;
  border = 3;
  active = false;

  rect.setSize(sf::Vector2f(width, height));
  rect.setPosition(pos);
  rect.setFillColor(sf::Color(190, 192, 196));
  rect.setOutlineThickness(border);
  rect.setOutlineColor(sf::Color(134, 142, 140));
}
void Button::render()
{
  ViewManager::get().getWindow()->draw(rect);
  ViewManager::get().getWindow()->draw(text);
}
Button *Button::onClick(std::function<void()>cb)
{
  callback = cb;
  return this;
}

Button *Button::setTxt(std::string txt)
{
  if (txt.size() == 5)
  {
    text.setPosition(sf::Vector2f(position.x + width * 0.28, position.y + height * 0.25));
  }
  else if (txt.size() >= 6)
    text.setPosition(sf::Vector2f(position.x + width * 0.2, position.y + height * 0.25));
  else
    text.setPosition(sf::Vector2f(position.x + width * 0.33, position.y + height * 0.25));
  text.setFillColor(sf::Color(247, 96, 119));
  text.setCharacterSize(25);
  text.setOutlineThickness(0.5);
  text.setOutlineColor(sf::Color(247, 96, 119));
  text.setFont(*AssetsManager::get().getFont());
  text.setString(txt);
}
void Button::handleEvent(sf::Event *e)
{

  if (e->type == sf::Event::MouseMoved || e->type == 9 || e->type == 10)
  {

    int x, y; //pozycja
    x = e->mouseButton.x;
    y = e->mouseButton.y;

    bool inside = true;
    if (x < position.x - border)
    {
      inside = false;
    }
    else if (x > position.x + width + border)
    {
      inside = false;
    }
    else if (y < position.y - border)
    {
      inside = false;
    }
    else if (y > position.y + height + border)
    {
      inside = false;
    }
    if (!inside)
    {
    }
    else
    {
      switch (e->type)
      {
      case sf::Event::MouseMoved:
        break;

      case 9:
        active = true;
        break;

      case 10:
        if (active)
        {
          callback();
        }
        active = false;
        break;
      }
    }
  }
}

void Button::changeColor(sf::Color col)
{
  text.setFillColor(col);
  text.setOutlineColor(col);
}