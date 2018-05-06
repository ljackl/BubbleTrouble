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
#include "GameEntity.hpp"

// TODO : https://stackoverflow.com/questions/18335861/why-is-enum-class-preferred-over-plain-enum#18335862
enum State
{
    STATE_SPLASHSCREEN,
    STATE_PLAY
};

class Bubble : GameEntity {


public:
    Bubble(float startX, float startY, State pState);

    void reboundSides();
    void reboundBottomOrTop();

    void handleEvents() override {}
    void update(sf::RenderWindow &window, sf::Time delta) override;
    void draw(sf::RenderWindow* window) override;

private:
    State state;
};

#endif //BUBBLETROUBLE_BLOB_H
