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
#include "GameEntity.hpp"

class Bullet : GameEntity {
public:
    Bullet(sf::FloatRect startPosition);

    void handleEvents() override {}
    void update(sf::RenderWindow& window, sf::Time delta) override;
    void draw(sf::RenderWindow& window, sf::Time delta) override;

};

#endif //BUBBLETROUBLE_BULLET_H
