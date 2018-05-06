//
// Created by pat on 18/04/18.
//

#include "Bubble.hpp"

// This the constructor and it is called when we create an object
Bubble::Bubble(float startX, float startY, State pState)
{
    position.x = startX;
    position.y = startY;

    state = pState;

    switch (state)
    {
        case STATE_SPLASHSCREEN:
            velocity.x = 6.0f;
            velocity.y = 6.0f;

            acceleration.x = 0.0f;
            acceleration.y = 0.0f;

            break;

        case STATE_PLAY:
            velocity.x = 0.0f;
            velocity.y = 0.0f;

            acceleration.x = 3.2f;
            acceleration.y = 9.8f;

            break;
    }

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
    //position.x -= (velocity.x * 30);
    velocity.x *= -1;
    acceleration.x *= -1;
}

void Bubble::reboundBottomOrTop()
{
    //position.y -= (velocity.y * 30);
    velocity.y *= -1;

}

void Bubble::update(sf::RenderWindow &window, sf::Time delta)
{
    switch (state)
    {
        case STATE_SPLASHSCREEN:
            if (getPosition().top < 0 || getPosition().top + 10 > window.getSize().y)
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

            if (getPosition().top + 10 > window.getSize().y)
            {
                velocity.y = -9.8f;
                acceleration.y = -20.2f;
            }

            if (getPosition().top > window.getSize().y / 2)
            {
                acceleration.y = 9.8f;
            }

            break;
    }

    velocity += acceleration * delta.asSeconds();

    // Limit vel
    velocity.x = static_cast<float>(fmin(3.8f, fmax(velocity.x, -3.8f)));
    velocity.y = static_cast<float>(fmin(9.8f, fmax(velocity.y, -9.8f)));

    // Update the ball position variables
    position += velocity;


    // Move the ball and the bat
    ballShape.setPosition(position);
}