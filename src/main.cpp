#ifdef _WIN32
#include "stdafx.h"
#endif

#include "Game.hpp"

int main() {
    Game game(640,480);

    game.init();
    while (game.running())
    {
        game.handleEvents();
        game.update();
        game.draw();
    }

    return 0;
}