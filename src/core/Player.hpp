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
#include "GameEntity.hpp"

class Player : public GameEntity {
public:
    Player(float startX, float startY);

    void handleEvents() override;
    void update(sf::RenderWindow &window, sf::Time delta) override;
    void draw(sf::RenderWindow* window) override;
};


#endif //BUBBLETROUBLE_PLAYER_H
