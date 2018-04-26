//
// Created by pat on 18/04/18.
//

#ifndef BUBBLETROUBLE_BLOB_H
#define BUBBLETROUBLE_BLOB_H

#include <SFML/Graphics.hpp>

class Blob
{
private:
    sf::Vector2f position;

    sf::RectangleShape ballShape;

    float xVelocity = .2f;
    float yVelocity = .2f;

public:
    Blob(float startX, float startY);

    sf::FloatRect getPosition();

    sf::RectangleShape getShape();

    float getXVelocity();

    void reboundSides();

    void reboundBatOrTop();

    void hitBottom();

    void update();

};

#endif //BUBBLETROUBLE_BLOB_H
