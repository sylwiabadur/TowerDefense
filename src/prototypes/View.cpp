#include "View.h"
std::string View::getName()
{
    return name;
}
void View::setName(std::string n)
{
    name = n;
}

void View::onDestroy(){} 
View::View() {}
View::~View() {}