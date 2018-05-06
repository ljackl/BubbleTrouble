//
// Created by pat on 6/05/18.
//

#include "Player.hpp"

Player::Player(float startX, float startY) {
    position.x = startX;
    position.y = startY;

    velocity.x = 0.0f;
    velocity.y = 0.0f;

    acceleration.x = 0.0f;
    acceleration.y = 0.0f;

    ballShape.setSize(sf::Vector2f(10, 10));
    ballShape.setPosition(position);
}

sf::FloatRect Player::getPosition() {
    return ballShape.getGlobalBounds();
}

sf::RectangleShape Player::getShape()
{
    return ballShape;
}

void Player::update(sf::RenderWindow &window, sf::Time delta)
{
    for (auto &item : bullets) {
        item->update(window, delta);
    }


    if (getPosition().left < 0)
    {
        position.x = window.getSize().x - 10;
    }

    if (getPosition().left + 10 > window.getSize().x) {
        position.x = 0;
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

void Player::handleEvents() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        // move left...
        acceleration.x = -3.0f;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        // move right...
        acceleration.x = 3.0f;
    } else {
        // stop moving
        acceleration.x = 0.0f;
        velocity.x /= 1.05f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        fireBullet();
    }
}

void Player::fireBullet() {
    bullets.push_back(new Bullet(position.x, position.y));
}
