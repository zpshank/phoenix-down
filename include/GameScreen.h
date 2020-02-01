#ifndef _GAMESCREEN_H_
#define _GAMESCREEN_H_

class PhoenixDownGame;
class GameState
{
public:
    GameState(PhoenixDownGame* game)
        :game(game)
    {};
    virtual void update() = 0;
    virtual void render(double frame_distance) = 0;
private:
    PhoenixDownGame* game;
};
#endif