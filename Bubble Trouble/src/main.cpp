
#include "core/Game.hpp"
#include "states/SplashGameState.hpp"

int main() {
    Game game(1280,720);

    game.pushState(new SplashGameState(&game));
    game.run();

    return 0;
}