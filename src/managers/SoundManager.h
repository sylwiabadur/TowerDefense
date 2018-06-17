#ifndef UNTITLED5_SOUNDMANAGER_H
#define UNTITLED5_SOUNDMANAGER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "AssetsManager.h"

class SoundManager
{

    std::vector<sf::Sound *> sounds;
    sf::Music music;

  public:
    SoundManager();
    static SoundManager &get();
    void playSound(std::string name);
    void playMusic(std::string name);
    void stopMusic();
};

#endif //UNTITLED5_SOUNDMANAGER_H