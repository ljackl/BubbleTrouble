//
// Created by pat on 26/04/18.
//

#ifndef BUBBLETROUBLE_GAMEOPTIONSGAMESTATE_H
#define BUBBLETROUBLE_GAMEOPTIONSGAMESTATE_H

#include "GameState.hpp"

class GameOptionsGameState : public GameState {
public:
    void update() override;
    void draw(sf::RenderWindow* window) override;
    void handleEvents(sf::RenderWindow* window, Game* game) override;
};


#endif //BUBBLETROUBLE_GAMEOPTIONSGAMESTATE_H
