
#ifdef _WIN32
#include "stdafx.h"
#endif

#include "Game.hpp"
#include "states/SplashGameState.hpp"

int main() {

    sf::Clock clock;

    Game game(640,480);

    game.changeState(new SplashGameState());

    while (game.running())
    {
        sf::Time elapsed = clock.restart();

        game.handleEvents();
        game.update(elapsed);
        game.draw();
    }

    return 0;
}