//
// Created by pat on 6/05/18.
//

#ifndef BUBBLETROUBLE_GAMEENTITY_H
#define BUBBLETROUBLE_GAMEENTITY_H

#include <cmath>
#include <SFML/Graphics.hpp>
#include "AnimationHandler.hpp"

class GameEntity {
protected:
    // Vector's : https://processing.org/tutorials/pvector/
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;

    AnimationHandler animationHandler;
    sf::Sprite sprite;

public:
    virtual void handleEvents() = 0;
    virtual void update(sf::RenderWindow& window, sf::Time delta) = 0;
    virtual void draw(sf::RenderWindow& window, sf::Time delta) = 0;

    const sf::Vector2f &getPosition() const {
        return position;
    }

    const sf::Vector2f &getVelocity() const {
        return velocity;
    }

    const sf::Vector2f &getAcceleration() const {
        return acceleration;
    }

    const sf::FloatRect getRect() const {
        return sprite.getGlobalBounds();
    }
};


#endif //BUBBLETROUBLE_GAMEENTITY_H
