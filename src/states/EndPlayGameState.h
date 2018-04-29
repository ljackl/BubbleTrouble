//
// Created by pat on 26/04/18.
//

#ifndef BUBBLETROUBLE_ENDPLAYGAMESTATE_H
#define BUBBLETROUBLE_ENDPLAYGAMESTATE_H

#include "GameState.hpp"

class EndPlayGameState : public GameState {
public:
    void update() override;
    void draw(sf::RenderWindow* window) override;
    void handleEvents(sf::RenderWindow* window, Game* game) override;
};


#endif //BUBBLETROUBLE_ENDPLAYGAMESTATE_H
