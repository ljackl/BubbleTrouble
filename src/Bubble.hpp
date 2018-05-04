//
// Created by pat on 18/04/18.
//

#ifndef BUBBLETROUBLE_BLOB_H
#define BUBBLETROUBLE_BLOB_H

#ifdef _WIN32
#include "stdafx.h"
#endif

#include <cmath>
#include <SFML/Graphics.hpp>

// TODO : https://stackoverflow.com/questions/18335861/why-is-enum-class-preferred-over-plain-enum#18335862
enum State
{
    STATE_SPLASHSCREEN,
    STATE_PLAY
};

class Bubble
{
private:
    // Vector's : https://processing.org/tutorials/pvector/
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;

    sf::RectangleShape ballShape;

    State state;

public:
    Bubble(float startX, float startY, State pState);

    sf::FloatRect getPosition();

    sf::RectangleShape getShape();

    void reboundSides();
    void reboundBottomOrTop();

    void update(sf::RenderWindow &window);

};

#endif //BUBBLETROUBLE_BLOB_H
