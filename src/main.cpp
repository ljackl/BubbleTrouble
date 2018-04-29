#include <iostream>
#include "Game.hpp"
#include "states/SplashGameState.hpp"

int main() {
    Game *game = new Game();
    game->init();

    game->ChangeState( new SplashGameState() );

    while (game->running())
    {
        game->handleEvents();
        game->update();
        game->draw();
    }

    return 0;
}