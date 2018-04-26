//
// Created by pat on 18/04/18.
//
#include "stdafx.h"

#include "Blob.hpp"

// This the constructor and it is called when we create an object
Blob::Blob(float startX, float startY)
{
    position.x = startX;
    position.y = startY;

    ballShape.setSize(sf::Vector2f(10, 10));
    ballShape.setPosition(position);
}

sf::FloatRect Blob::getPosition()
{
    return ballShape.getGlobalBounds();
}

sf::RectangleShape Blob::getShape()
{
    return ballShape;
}

float Blob::getXVelocity()
{
    return xVelocity;
}

void Blob::reboundSides()
{
    xVelocity = -xVelocity;
}

void Blob::reboundBatOrTop()
{
    position.y -= (yVelocity * 30);
    yVelocity = -yVelocity;

}

void Blob::hitBottom()
{
    position.y = 1;
    position.x = 500;
}

void Blob::update()
{
    // Update the ball position variables
    position.y += yVelocity;
    position.x += xVelocity;

    // Move the ball and the bat
    ballShape.setPosition(position);
}