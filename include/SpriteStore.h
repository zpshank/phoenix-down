#ifndef _SPRITESTORE_H_
#define _SPRITESTORE_H_
#include <Sprite.h>
#include <string>
#include <SDL_render.h>
#include <map>

namespace pp = powderpuff;

class SpriteStore
{
public:
    pp::Sprite* sprite(const std::string & name);
    void addSprite(const std::string& name, SDL_Texture* texture);
private:
    std::map<std::string, pp::Sprite> sprites;
};
#endif