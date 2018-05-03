//
// Created by pat on 18/04/18.
//

#include "Bubble.hpp"

// This the constructor and it is called when we create an object
Bubble::Bubble(float startX, float startY)
{
    position.x = startX;
    position.y = startY;

    ballShape.setSize(sf::Vector2f(10, 10));
    ballShape.setPosition(position);
}

sf::FloatRect Bubble::getPosition()
{
    return ballShape.getGlobalBounds();
}

sf::RectangleShape Bubble::getShape()
{
    return ballShape;
}

float Bubble::getXVelocity()
{
    return xVelocity;
}

void Bubble::reboundSides()
{
    xVelocity = -xVelocity;
}

void Bubble::reboundBatOrTop()
{
    position.y -= (yVelocity * 30);
    yVelocity = -yVelocity;

}

void Bubble::hitBottom()
{
    position.y = 1;
    position.x = 500;
}

void Bubble::update(sf::RenderWindow &window)
{
    if (getPosition().top > window.getSize().y)
    {
        reboundBatOrTop();
    }

    if (getPosition().left < 0 || getPosition().left + 10 > window.getSize().x)
    {
        reboundSides();
    }

    if (getPosition().top < 0)
    {
        reboundBatOrTop();
    }

    // Update the ball position variables
    position.y += yVelocity;
    position.x += xVelocity;

    // Move the ball and the bat
    ballShape.setPosition(position);
}