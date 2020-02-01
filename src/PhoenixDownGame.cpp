#include <PhoenixDownGame.h>
#include <Constants.h>

PhoenixDownGame::PhoenixDownGame()
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
    loadAssets();
    pp:Game::run();
}

void PhoenixDownGame::loadAssets()
{
    std::string asset_dir = SDL_GetBasePath();
    asset_dir.append("assets/");

    asset_store.addImage(renderer, Constants::PHOENIX, std::string(asset_dir + Constants::PHOENIX + ".png"));
    sprites.addSprite(Constants::PHOENIX, asset_store.image(Constants::PHOENIX));
}

void PhoenixDownGame::render(double frame_distance)
{
    clearScreen();

    pp::Sprite* phoenix = sprites.sprite(Constants::PHOENIX);
    phoenix->draw(renderer, 0, 0);

    SDL_RenderPresent(renderer);
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
