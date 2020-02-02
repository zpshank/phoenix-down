#ifndef _PHOENIXDOWNGAME_H_
#define _PHOENIXDOWNGAME_H_
#include <Game.h>
#include <SDL.h>
#include <SpriteStore.h>
#include <Phoenix.h>
#include <deque>
#include <Creature.h>

namespace pp = powderpuff;

class GameScreen;
class DungeonScreen;
enum EnemyType
{
    SLIME = 1
    , SKELETON = 2
    , WOLF = 3
    , GHOST = 4
};
class PhoenixDownGame : public pp::Game
{
public:
    explicit PhoenixDownGame();
    void render(double frame_distance) override;
    void start();
    void loadAssets();
    void update() override;
    void setCurrentScreen(GameScreen* new_screen);
    friend class GameScreen;
    friend class DungeonScreen;
private:
    const int GAME_WIDTH = 84;
    const int GAME_HEIGHT = 48;
    const int DUNGEON_LENGTH = 10; // Number of baddies
    const SDL_Color BACKGROUND_COLOR = { 0xc7, 0xf0, 0xd8, 255 };
    const SDL_Rect BACKGROUND_RECT = { 0, 0, GAME_WIDTH, GAME_HEIGHT };
    const SDL_Color FOREGROUND_COLOR = { 0x43, 0x52, 0x3d, 255 };
    bool is_loaded = false;
    SpriteStore sprites;
    GameScreen* current_screen;
    void setupDungeonRun();
    void setupDungeon();

    Phoenix phoenix;
    std::deque<Creature>dungeon;

    void clearScreen();
};

#endif