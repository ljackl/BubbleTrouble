//
// Created by pat on 18/04/18.
//

#include "Bubble.hpp"

// This the constructor and it is called when we create an object
Bubble::Bubble(float startX, float startY, State pState, sf::Texture& texture)
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

    shape.setSize(sf::Vector2f(20, 20));
    shape.setPosition(position);

    sf::Vector2f targetSize(20.0f, 20.0f);
    this->sprite.setOrigin(sf::Vector2f(0.0f, 0.0f));
    this->sprite.setTexture(texture);

    this->sprite.setScale(
            targetSize.x / this->sprite.getLocalBounds().width,
            targetSize.y / this->sprite.getLocalBounds().height);

    this->sprite.setPosition(position);
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

void Bubble::update(sf::RenderWindow& window, sf::Time delta)
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

    // Move the bubble
    shape.setPosition(position);
    this->sprite.setPosition(position);
}

void Bubble::draw(sf::RenderWindow& window, sf::Time delta) {
    // Draw this
    window.draw(this->sprite);
}

void Bubble::popBubble() {
    switch (popState)
    {
        case POP_ONE:
            popState = POP_TWO;
            shape.setSize(sf::Vector2f(shape.getSize().x / 2, shape.getSize().y / 2));
            sprite.scale(sf::Vector2f(0.5f, 0.5f));
            break;

        case POP_TWO:
            popState = POP_THREE;
            shape.setSize(sf::Vector2f(shape.getSize().x / 2, shape.getSize().y / 2));
            sprite.scale(sf::Vector2f(0.5f, 0.5f));
            break;

        case POP_THREE:
            shape.setSize(sf::Vector2f(0, 0));
            shape.setPosition(-1000, -1000);
            popState = POPPED;
            break;

        case POPPED:break;
    }
}
