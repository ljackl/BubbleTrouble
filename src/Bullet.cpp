//
// Created by pat on 6/05/18.
//

#include "Bullet.hpp"

Bullet::Bullet(float startX, float startY) {
    position.x = startX;
    position.y = startY;

    velocity.x = 0.0f;
    velocity.y = -9.8f;

    acceleration.x = 0.0f;
    acceleration.y = 0.0f;

    ballShape.setSize(sf::Vector2f(2, 2));
    ballShape.setPosition(position);
}

sf::FloatRect Bullet::getPosition() {
    return ballShape.getGlobalBounds();
}

sf::RectangleShape Bullet::getShape()
{
    return ballShape;
}

void Bullet::update(sf::RenderWindow &window, sf::Time delta)
{
    if (getPosition().top < 0)
    {
        // non exists
    }

    velocity += acceleration * delta.asSeconds();

    // Limit vel
    //velocity.x = static_cast<float>(fmin(3.8f, fmax(velocity.x, -3.8f)));
    //velocity.y = static_cast<float>(fmin(9.8f, fmax(velocity.y, -9.8f)));

    // Update the ball position variables
    position += velocity;

    // Move the ball and the bat
    ballShape.setPosition(position);
}
