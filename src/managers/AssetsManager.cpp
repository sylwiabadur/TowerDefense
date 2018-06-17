#include "AssetsManager.h"
#include <dirent.h>
#include <string>

AssetsManager::AssetsManager()
{
    textures = loadAssets<sf::Texture>("assets/textures");
    soundBuffers = loadAssets<sf::SoundBuffer>("assets/sounds");
    font = new sf::Font;
    if (!font->loadFromFile("assets/arial.ttf"))
    {
        std::cout << "Failed to load font" << std::endl;
    }
    else
        std::cout << "Font loaded" << std::endl;
}
sf::Font *AssetsManager::getFont()
{
    return font;
}

template <typename T>
std::map<std::string, T *> AssetsManager::loadAssets(std::string name)
{
    std::map<std::string, T *> m;
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(name.c_str())) != NULL)
    {
        std::cout << "Loading " + name << std::endl;
        while ((ent = readdir(dir)) != NULL)
        {
            if (std::string(ent->d_name) == "." || std::string(ent->d_name) == "..")
                continue;
            else
            {
                std::cout << name + "/" + ent->d_name << std::endl;
                m[ent->d_name] = new T;
                // std::cout << "1" << std::endl;
                m[ent->d_name]->loadFromFile(name + "/" + ent->d_name);
                //std::cout << "2" << std::endl;
            }
        }
        std::cout << "Loaded " + name + " -------" << std::endl;
        closedir(dir);
    }
    else
    {
        perror("could not open directory");
    }
    return m;
}

sf::Texture *AssetsManager::getTexture(std::string name)
{
    return textures[name];
}

sf::SoundBuffer *AssetsManager::getSoundBuffer(std::string name)
{
    return soundBuffers[name];
}

AssetsManager &AssetsManager::get()
{
    static AssetsManager manager;
    return manager;
}