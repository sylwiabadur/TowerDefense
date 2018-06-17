#include "ViewManager.h"
ViewManager::ViewManager()
{
}
ViewManager::ViewManager(const ViewManager &)
{
    quit = false;
    vwindow->close();
}

ViewManager &ViewManager::get()
{
    static ViewManager manager;
    return manager;
}
void ViewManager::exit()
{
    quit = true;
}
void ViewManager::addView(View *v)
{
    views[v->getName()] = v;
}
void ViewManager::remoweView(std::string name)
{
    views.erase(name);
}
void ViewManager::changeView(std::string name)
{
    if (view != NULL)
        view->onDestroy();

    view = views[name];
    view->init();
}
void ViewManager::updateView()
{
    view->init();
}
void ViewManager::assignWindow(sf::RenderWindow *window)
{
    vwindow = window;
}
sf::RenderWindow *ViewManager::getWindow()
{
    return vwindow;
}

void ViewManager::renderView()
{
    vwindow->clear();
    view->render(vwindow);
    vwindow->display();
}
void ViewManager::handleEvent(sf::Event *e)
{
    if (view != NULL)
    {
        view->handleEvent(e);
    }
    else
    {
        std::cout << "View is NULL";
    }
}