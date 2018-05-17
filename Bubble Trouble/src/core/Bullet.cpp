//
// Created by pat on 6/05/18.
//

#include "Bullet.hpp"

Bullet::Bullet(sf::FloatRect startPosition, sf::Texture& texture) {
    position.x = startPosition.left;
    position.y = startPosition.top;

    velocity.x = 0.0f;
    velocity.y = -9.8f;

    acceleration.x = 0.0f;
    acceleration.y = 0.0f;

    this->sprite.setTexture(texture);

    sf::Vector2f targetSize(15.0f, 10.0f);
    this->sprite.setScale(
            targetSize.x / this->sprite.getLocalBounds().width,
            targetSize.y / this->sprite.getLocalBounds().height);

    this->sprite.rotate(90);
    this->sprite.setOrigin(sf::Vector2f(this->sprite.getLocalBounds().width / 2, this->sprite.getLocalBounds().height / 2));
    this->sprite.setPosition(position);
}

void Bullet::update(sf::RenderWindow& window, sf::Time delta)
{
    if (getRect().top < 0)
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
    this->sprite.setPosition(position);
}

void Bullet::draw(sf::RenderWindow& window, sf::Time delta) {
    // Draw this
    window.draw(this->sprite);
}
