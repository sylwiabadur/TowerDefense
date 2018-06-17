#ifndef UNTITLED5_VIEW_H
#define UNTITLED5_VIEW_H
#include <SFML/Graphics.hpp>
#include <string>

class View{
    protected:
    std::string name; 
    public:
    std::string getName();
    void setName (std::string n);
    virtual void render(sf::RenderWindow *window)=0; 
    virtual void handleEvent(sf::Event *event)=0;
    virtual void init()=0;

    virtual void onDestroy();

    View();
    ~View();

};
#endif //UNTITLED5_VIEW_H