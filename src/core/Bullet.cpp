//
// Created by pat on 6/05/18.
//

#include "Bullet.hpp"

Bullet::Bullet(sf::FloatRect startPosition) {
    position.x = startPosition.left;
    position.y = startPosition.top;

    velocity.x = 0.0f;
    velocity.y = -9.8f;

    acceleration.x = 0.0f;
    acceleration.y = 0.0f;

    shape.setSize(sf::Vector2f(2, 2));
    shape.setPosition(position);
}

void Bullet::update(sf::RenderWindow& window, sf::Time delta)
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
    shape.setPosition(position);
}

void Bullet::draw(sf::RenderWindow& window, sf::Time delta) {
    // Draw this
    window.draw(getShape());
}
