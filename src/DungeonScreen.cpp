#include <DungeonScreen.h>
#include <Constants.h>
#include <iostream>
#include <PhoenixDownGame.h>
#include <algorithm>

DungeonScreen::DungeonScreen(Creature* fighter, std::deque<Creature>* dungeon, PhoenixDownGame* game)
    :GameScreen(game)
    , fighter(fighter)
    , dungeon(dungeon)
{
}

void DungeonScreen::update()
{
    tick++;

    if (dungeon->empty())
    {
        //TODO Handle dungeon complete state
        std::cout << "A winner is you!" << std::endl;
        return;
    }

    switch (mode)
    {
    case DungeonScreen::Mode::FIGHTING:
        // Look if need to attack
        if (tick == Constants::TICK_HERTZ)
        {
            // Attack
            Creature enemy = dungeon->at(0);
            fighter->attack(enemy);
            enemy.attack(*fighter);

            if (enemy.isDead())
            {
                mode = DungeonScreen::Mode::ENEMY_DYING;
            }

            if (fighter->isDead())
            {
                std::cout << "You are dead. :(" << std::endl;
            }
        }

        tick = tick % Constants::TICK_HERTZ;
        break;
    case DungeonScreen::Mode::ENEMY_DYING:
        if (tick == Constants::TICK_HERTZ / 2)
        {
            dungeon->pop_front();
            mode = DungeonScreen::Mode::ENEMY_ENTERING;
            tick = 0;
        }
        break;
    case DungeonScreen::Mode::ENEMY_ENTERING:
        if (tick == Constants::TICK_HERTZ / 2)
        {
            mode = DungeonScreen::Mode::FIGHTING;
            tick = 0;
        }
        break;
    }
}

void DungeonScreen::render(double frame_distance)
{
    int padding = 10;
    // Shift in last tenth of a second
    int attack_offset = (tick + (Constants::TICK_HERTZ / 4) > Constants::TICK_HERTZ) ? 2 : 0;

    // Draw Fighter
    fighter->sprite()->draw(game->renderer, padding + attack_offset, padding);
    drawHealthBar(fighter->initHealth(), fighter->health(), padding, padding + fighter->sprite()->frameHeight() + 1);

    // Draw Enemy Based on mode
    if (!dungeon->empty())
    {
        Creature enemy = dungeon->at(0);
        pp::Sprite* enemy_sprite = enemy.sprite();
        int enemy_width = enemy_sprite->frameWidth() + padding;
        int enemy_x = game->GAME_WIDTH - enemy_width;
    switch (mode)
    {
    case DungeonScreen::Mode::FIGHTING:
        enemy_sprite->draw(game->renderer, enemy_x - attack_offset, padding);
        drawHealthBar(enemy.initHealth()
            , enemy.health()
            , game->GAME_WIDTH - enemy_sprite->frameWidth() - padding
            , padding + enemy_sprite->frameHeight() + 1);
        break;
    case DungeonScreen::Mode::ENEMY_DYING:
        // Slide off screen in half a second
        enemy_x += static_cast<double>(enemy_width)* (static_cast<double>(tick) / (Constants::TICK_HERTZ / 2));
        enemy_sprite->draw(game->renderer, enemy_x, padding);
        break;
    case DungeonScreen::Mode::ENEMY_ENTERING:
        // Slide on screen in half a second
        enemy_x += static_cast<double>(enemy_width)* (static_cast<double>((Constants::TICK_HERTZ / 2) - tick) / (Constants::TICK_HERTZ / 2));
        enemy_sprite->draw(game->renderer, enemy_x, padding);
        break;
    }
    }

}

void DungeonScreen::drawHealthBar(const int init_health, const int health, const int x, const int y)
{
    // Get health tick width
    int padding = 1;
    int health_tick_height = 3;
    int health_tick_width = 2;

    SDL_SetRenderDrawBlendMode(game->renderer, SDL_BLENDMODE_NONE);
    SDL_SetRenderDrawColor(game->renderer
        , game->FOREGROUND_COLOR.r
        , game->FOREGROUND_COLOR.g
        , game->FOREGROUND_COLOR.b
        , game->FOREGROUND_COLOR.a);
    for (int i = 0; i < health; i++)
    {
        SDL_Rect health_tick_rect{ x + (health_tick_width + padding) * i, y, health_tick_width, health_tick_height };

        SDL_RenderFillRect(game->renderer, &health_tick_rect);
    }
}