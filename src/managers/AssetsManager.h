#ifndef UNTITLED5_ASSETSMANAGER_H
#define UNTITLED5_ASSETSMANAGER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <map>

class AssetsManager
{

  std::map<std::string, sf::Texture *> textures;
  std::map<std::string, sf::SoundBuffer *> soundBuffers;
  sf::Font *font;

  template <typename T>
  std::map<std::string, T *> loadAssets(std::string name);

public:
  AssetsManager();
  static AssetsManager &get();

  sf::Texture *getTexture(std::string name);
  sf::SoundBuffer *getSoundBuffer(std::string name);
  sf::Font *getFont();
};

#endif //UNTITLED5_ASSETSMANAGER_H