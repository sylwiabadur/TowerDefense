#ifndef UNTITLED5_VIEWMANAGER_H
#define UNTITLED5_VIEWMANAGER_H
#include <SFML/Graphics.hpp>
#include "../prototypes/View.h"
#include <string>
#include <iostream>

class ViewManager
{
  std::map<std::string, View *> views;
  View *view = NULL;
  ViewManager();
  ViewManager(const ViewManager &);
  sf::RenderWindow *vwindow; 
 

public:
  bool quit;
  void exit();
  void addView(View *v);
  void remoweView(std::string name);
  void changeView(std::string name);
  void updateView();
  void assignWindow(sf::RenderWindow *window);
  sf::RenderWindow *getWindow();
  
  void renderView();
  void handleEvent(sf::Event *e);

  static ViewManager &get();
};

#endif //UNTITLED5_VIEWMANAGER_H