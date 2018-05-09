//
// Created by pat on 6/05/18.
//

#ifndef BUBBLETROUBLE_BULLET_H
#define BUBBLETROUBLE_BULLET_H

#include <cmath>
#include <SFML/Graphics.hpp>
#include "GameEntity.hpp"

class Bullet : public GameEntity {
public:
    Bullet(sf::FloatRect startPosition);

    void handleEvents() override {}
    void update(sf::RenderWindow& window, sf::Time delta) override;
    void draw(sf::RenderWindow& window, sf::Time delta) override;

    bool isOutOfYFrame() { return position.y < 0; }

};

#endif //BUBBLETROUBLE_BULLET_H
