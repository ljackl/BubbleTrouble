//
// Created by pat on 6/05/18.
//

#ifndef BUBBLETROUBLE_GAMEENTITY_H
#define BUBBLETROUBLE_GAMEENTITY_H

#ifdef _WIN32
#include "stdafx.h"
#endif

#include <cmath>
#include <SFML/Graphics.hpp>

class GameEntity {
protected:
    // Vector's : https://processing.org/tutorials/pvector/
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;

    sf::RectangleShape shape;

public:
    sf::FloatRect getPosition();
    sf::RectangleShape getShape();

    virtual void handleEvents() = 0;
    virtual void update(sf::RenderWindow &window, sf::Time delta) = 0;
    virtual void draw(sf::RenderWindow* window) = 0;
};


#endif //BUBBLETROUBLE_GAMEENTITY_H
