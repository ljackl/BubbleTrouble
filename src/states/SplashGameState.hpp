//
// Created by pat on 26/04/18.
//

#ifndef BUBBLETROUBLE_SPLASHGAMESTATE_H
#define BUBBLETROUBLE_SPLASHGAMESTATE_H

#include "GameState.hpp"

class SplashGameState : public GameState {
public:
    void update() override;
    void draw(sf::RenderWindow* window) override;
    void handleEvents(sf::RenderWindow* window, Game* game) override;
};


#endif //BUBBLETROUBLE_SPLASHGAMESTATE_H
