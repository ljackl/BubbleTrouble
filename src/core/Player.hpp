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
    Player() {}
    Player(float startX, float startY, sf::Texture& texture, const std::vector<Animation>& animations);

    void handleEvents() override;
    void update(sf::RenderWindow& window, sf::Time delta) override;
    void draw(sf::RenderWindow& window, sf::Time delta) override;
};


#endif //BUBBLETROUBLE_PLAYER_H
