
#ifdef _WIN32
#include "stdafx.h"
#endif

#include "Game.hpp"
#include "states/SplashGameState.hpp"

int main() {
    Game game(640,480);

    game.ChangeState( new SplashGameState() );

    while (game.running())
    {
        game.handleEvents();
        game.update();
        game.draw();
    }

    return 0;
}