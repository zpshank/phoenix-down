#ifndef _PHOENIXDOWNGAME_H_
#define _PHOENIXDOWNGAME_H_
#include <Game.h>
#include <SDL.h>
#include <SpriteStore.h>

namespace pp = powderpuff;

class PhoenixDownGame : public pp::Game
{
public:
    explicit PhoenixDownGame();
    void render(double frame_distance) override;
    void start();
    void loadAssets();
private:
    const int GAME_WIDTH = 84;
    const int GAME_HEIGHT = 48;
    const SDL_Color BACKGROUND_COLOR = { 0xc7, 0xf0, 0xd8, 255 };
    const SDL_Rect BACKGROUND_RECT = { 0, 0, GAME_WIDTH, GAME_HEIGHT };
    bool is_loaded = false;
    SpriteStore sprites;
    

    void clearScreen();
};

#endif