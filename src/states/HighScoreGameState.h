//
// Created by pat on 26/04/18.
//

#ifndef BUBBLETROUBLE_HIGHSCOREGAMESTATE_H
#define BUBBLETROUBLE_HIGHSCOREGAMESTATE_H

#include "GameState.hpp"

class HighScoreGameState : public GameState {
public:
    void update() override;
    void draw(sf::RenderWindow* window) override;
    void handleEvents(sf::RenderWindow* window, Game* game) override;
};


#endif //BUBBLETROUBLE_HIGHSCOREGAMESTATE_H
