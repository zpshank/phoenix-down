#ifndef _GAMESCREEN_H_
#define _GAMESCREEN_H_
#include <SDL.h>

class PhoenixDownGame;
class GameScreen
{
public:
    GameScreen(PhoenixDownGame* game)
        :game(game)
    {};
    virtual void update() = 0;
    virtual void render(double frame_distance) = 0;
    virtual void handleEvent(const SDL_Event & event){};
protected:
    PhoenixDownGame* game;
};
#endif