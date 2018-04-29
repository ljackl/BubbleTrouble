//
// Created by pat on 26/04/18.
//

#ifndef BUBBLETROUBLE_HELPGAMESTATE_H
#define BUBBLETROUBLE_HELPGAMESTATE_H

#include "GameState.hpp"

class HelpGameState : public GameState {
public:
    void update() override;
    void draw(sf::RenderWindow* window) override;
    void handleEvents(sf::RenderWindow* window, Game* game) override;
};


#endif //BUBBLETROUBLE_HELPGAMESTATE_H
