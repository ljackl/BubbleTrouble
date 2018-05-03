//
// Created by pat on 26/04/18.
//

#ifndef BUBBLETROUBLE_MENUGAMESTATE_H
#define BUBBLETROUBLE_MENUGAMESTATE_H

#include "GameState.hpp"

class MenuGameState : public GameState {
public:
    void update() override;
    void draw(sf::RenderWindow* window) override;
    void handleEvents(sf::RenderWindow* window, Game* game) override;
};


#endif //BUBBLETROUBLE_MENUGAMESTATE_H
