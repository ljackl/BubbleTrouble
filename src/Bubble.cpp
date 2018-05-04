//
// Created by pat on 18/04/18.
//

#include "Bubble.hpp"

// This the constructor and it is called when we create an object
Bubble::Bubble(float startX, float startY, State pState)
{
    position.x = startX;
    position.y = startY;

    velocity.x = 0.1f;
    velocity.y = 0.1f;

    acceleration.x = 0.0f;
    acceleration.y = 0.0f;

    state = pState;

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

void Bubble::reboundSides()
{
    position.x -= (velocity.x * 30);
    velocity.x *= -1;
}

void Bubble::reboundBottomOrTop()
{
    position.y -= (velocity.y * 30);
    velocity.y *= -1;

}

void Bubble::update(sf::RenderWindow &window)
{
    switch (state)
    {
        case STATE_SPLASHSCREEN:
            if (getPosition().top < 0 || getPosition().top > window.getSize().y)
            {
                reboundBottomOrTop();
            }

            if (getPosition().left < 0 || getPosition().left + 10 > window.getSize().x)
            {
                reboundSides();
            }

            break;
        case STATE_PLAY:
            // https://gamedev.stackexchange.com/questions/121389/how-i-can-make-better-jump-to-my-game-c-sfml
            if (getPosition().left < 0 || getPosition().left + 10 > window.getSize().x)
            {
                reboundSides();
            }

            if (getPosition().top > window.getSize().y)
            {
                velocity.y = -0.2f;
                acceleration.y = -0.0001f;
            }

            if (getPosition().top > window.getSize().y / 2)
            {
                acceleration.y = 0.0001f;
            }

            break;
    }

    // Update the ball position variables
    velocity += acceleration;

    //velocity.x = fmin(MAX_VELOCITY, fmax(velocity.x, -MAX_VELOCITY));
    //velocity.y = fmin(MAX_VELOCITY, fmax(velocity.y, -MAX_VELOCITY));

    position += velocity;


    // Move the ball and the bat
    ballShape.setPosition(position);
}