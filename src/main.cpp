
#ifdef _WIN32
#include "stdafx.h"
#endif

#include "core/Game.hpp"
#include "states/SplashGameState.hpp"

int main() {
    Game game(640,480);

    game.pushState(new SplashGameState(&game));
    game.run();

    return 0;
}