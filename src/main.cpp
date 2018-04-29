#ifdef _WIN32
#include "stdafx.h"
#endif

#include "Game.hpp"

int main() {
    Game *game = new Game();
    game->init();

    while (game->running())
    {
        game->handleEvents();
        game->update();
        game->draw();
    }

    return 0;
}