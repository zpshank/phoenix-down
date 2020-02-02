#ifndef _DUNGEONSCREEN_H_
#define _DUNGEONSCREEN_H_
#include <GameScreen.h>
#include <Creature.h>
#include <deque>

class DungeonScreen : public GameScreen
{
    enum class Mode
    {
        FIGHTING
        , ENEMY_ENTERING
        , ENEMY_DYING
    };
public:
    DungeonScreen(Creature* fighter, std::deque<Creature>* dungeon, PhoenixDownGame* game);
    void update() override;
    void render(double frame_distance) override;
private:
    void drawHealthBar(const int init_health, const int health, const int x, const int y);
    std::deque<Creature>* dungeon;
    Creature* fighter;
    int tick = 0;
    Mode mode = DungeonScreen::Mode::FIGHTING;
};
#endif