//
// Created by pat on 26/04/18.
//

#ifndef BUBBLETROUBLE_PLAYGAMESTATE_H
#define BUBBLETROUBLE_PLAYGAMESTATE_H

#include "GameState.hpp"

class PlayGameState : public GameState {
public:
    void update() override;
    void draw(sf::RenderWindow* window) override;
    void handleEvents(sf::RenderWindow* window, Game* game) override;
};


#endif //BUBBLETROUBLE_PLAYGAMESTATE_H
