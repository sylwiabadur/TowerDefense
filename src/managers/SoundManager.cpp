#include "SoundManager.h"

SoundManager::SoundManager()
{
}

SoundManager &SoundManager::get()
{
    static SoundManager manager;
    return manager;
}
void SoundManager::playSound(std::string name)
{
    sf::Sound *sound = new sf::Sound();
    sound->setBuffer(*AssetsManager::get().getSoundBuffer(name));
    sound->play();
    for (int i = 0; i < sounds.size(); i++)
    {
        if (sounds.at(i)->getStatus() == sf::SoundSource::Status::Stopped)
        {
            sounds.erase(sounds.begin() + i--);
        }
    }
    sounds.push_back(sound);
}

void SoundManager::playMusic(std::string name)
{
    music.openFromFile("assets/music/" + name);
    music.setLoop(true);
    music.setVolume(50);
    music.play();
}

void SoundManager::stopMusic()
{
    music.stop();
}