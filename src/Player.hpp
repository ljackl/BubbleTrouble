//
// Created by pat on 6/05/18.
//

#ifndef BUBBLETROUBLE_PLAYER_H
#define BUBBLETROUBLE_PLAYER_H

#ifdef _WIN32
#include "stdafx.h"
#endif

#include <cmath>
#include <SFML/Graphics.hpp>
#include "Bullet.hpp"

class Player {
private:
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;

    sf::RectangleShape ballShape;



public:
    Player(float startX, float startY);

    sf::FloatRect getPosition();

    sf::RectangleShape getShape();

    void update(sf::RenderWindow &window, sf::Time delta);
    void handleEvents();

    std::vector<Bullet*> bullets;
    void fireBullet();

};


#endif //BUBBLETROUBLE_PLAYER_H
