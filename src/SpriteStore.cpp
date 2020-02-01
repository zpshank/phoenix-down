#include <SpriteStore.h>

pp::Sprite* SpriteStore::sprite(const std::string& name)
{
    auto it = sprites.find(name);

    // Not found
    if (it == sprites.end())
    {
        return nullptr;
    }

    return &(it->second);

}

void SpriteStore::addSprite(const std::string& name, SDL_Texture* texture)
{
    pp::Sprite sprite;
    sprite.loadTexture(texture);
    sprites.insert(std::pair<std::string, pp::Sprite>(name, sprite));
}
