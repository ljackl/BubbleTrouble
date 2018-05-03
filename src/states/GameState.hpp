//
// Created by pat on 26/04/18.
//

#ifndef BUBBLETROUBLE_GAMESTATE_H
#define BUBBLETROUBLE_GAMESTATE_H

#include <SFML/Graphics.hpp>

class Game;
// https://www.binpress.com/tutorial/creating-a-city-building-game-with-sfml-part-1-state-manager/123
class GameState {
public:
    virtual void update(sf::RenderWindow* window) = 0;
    virtual void draw(sf::RenderWindow* window) = 0;
    virtual void handleEvents(sf::RenderWindow* window, Game* game) = 0;
};

#endif //BUBBLETROUBLE_GAMESTATE_H
