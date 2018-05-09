//
// Created by pat on 26/04/18.
//

#ifndef BUBBLETROUBLE_GAMESTATE_H
#define BUBBLETROUBLE_GAMESTATE_H

#include <SFML/Graphics.hpp>
#include "../core/Game.hpp"

class Game;

class GameState {
public:
    Game* game;

    virtual void handleEvents() = 0;
    virtual void update(sf::Time delta) = 0;
    virtual void draw(sf::Time delta) = 0;
};

#endif //BUBBLETROUBLE_GAMESTATE_H
