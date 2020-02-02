#include <PhoenixDownGame.h>
#include <Constants.h>
#include <GameScreen.h>
#include <DungeonScreen.h>
#include <Slime.h>
#include <vector>

PhoenixDownGame::PhoenixDownGame()
    :current_screen(nullptr)
{
}

void PhoenixDownGame::start()
{
    pp::Game::init(
        "Phoenix Down"
        , 840, 480
        , SDL_WINDOW_RESIZABLE
        , GAME_WIDTH, GAME_HEIGHT
    );
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
    loadAssets();

    setupDungeonRun();

    pp:Game::run();
}

void PhoenixDownGame::loadAssets()
{
    std::string asset_dir = SDL_GetBasePath();
    asset_dir.append("assets/");

    std::vector<std::string> asset_names({
        Constants::PHOENIX
        , Constants::SLIME
    });

    for (auto asset_name : asset_names)
    {
        asset_store.addImage(renderer, asset_name, std::string(asset_dir + asset_name + ".png"));
        sprites.addSprite(asset_name, asset_store.image(asset_name));
    }

}

void PhoenixDownGame::setupDungeonRun()
{
    phoenix.reset();
    phoenix.setSprite(sprites.sprite(Constants::PHOENIX));

    // TODO setup dungeon
    setupDungeon();

    setCurrentScreen(new DungeonScreen(&phoenix, &dungeon, this));
}

void PhoenixDownGame::setupDungeon()
{
    dungeon.clear();

    // Always start with a slime
    Slime slime(sprites.sprite(Constants::SLIME));
    dungeon.push_back(slime);

    int i = 1;
    while (i < DUNGEON_LENGTH)
    {
        int random_idx = rand() % 1 + 1;
        switch (random_idx)
        {
        case SLIME:
            Slime slime(sprites.sprite(Constants::SLIME));
            dungeon.push_back(slime);
            break;
        }
        i++;
    }
}

void PhoenixDownGame::render(double frame_distance)
{
    clearScreen();

    if (current_screen)
    {
        current_screen->render(frame_distance);
    }

    SDL_RenderPresent(renderer);
}

void PhoenixDownGame::update()
{
    if (current_screen)
    {
        current_screen->update();
    }
}

void PhoenixDownGame::clearScreen()
{
    SDL_SetRenderDrawColor(renderer
        , BACKGROUND_COLOR.r
        , BACKGROUND_COLOR.g
        , BACKGROUND_COLOR.b
        , BACKGROUND_COLOR.a
    );
    SDL_RenderFillRect(renderer, &BACKGROUND_RECT);
}

void PhoenixDownGame::setCurrentScreen(GameScreen* new_screen)
{
    delete current_screen;
    current_screen = nullptr;
    current_screen = new_screen;
}
