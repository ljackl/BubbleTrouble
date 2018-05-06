//
// Created by pat on 6/05/18.
//

#ifndef BUBBLETROUBLE_BULLET_H
#define BUBBLETROUBLE_BULLET_H

#ifdef _WIN32
#include "stdafx.h"
#endif

#include <cmath>
#include <SFML/Graphics.hpp>

class Bullet {
private:
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;

    sf::RectangleShape ballShape;

public:
    Bullet(float startX, float startY);

    sf::FloatRect getPosition();

    sf::RectangleShape getShape();

    void update(sf::RenderWindow &window, sf::Time delta);
    void handleEvents();

};


#endif //BUBBLETROUBLE_BULLET_H
