//
// Created by pat on 6/05/18.
//

#include "Player.hpp"

Player::Player(sf::Vector2f position, sf::Texture& texture, const std::vector<Animation>& animations) {
    this->position = position;

    velocity.x = 0.0f;
    velocity.y = 0.0f;

    acceleration.x = 0.0f;
    acceleration.y = 0.0f;

    this->sprite.setOrigin(sf::Vector2f(0.0f, 0.0f));
    this->sprite.setTexture(texture);

    this->animationHandler.frameSize = sf::IntRect(0, 0, 72, 96);
    for(auto animation : animations)
    {
        this->animationHandler.addAnimimatin(animation);
    }
    this->animationHandler.changeAnim(0);
    this->animationHandler.update(0.0f);
    this->sprite.setTextureRect(this->animationHandler.bounds);

    this->sprite.scale(0.5f, 0.5f);

    this->position.y -= this->sprite.getGlobalBounds().height;
    this->sprite.setPosition(position);
}

void Player::handleEvents() {
    moving = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        // move left...
        acceleration.x = -6.0f;
        moving = true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        // move right...
        acceleration.x = 6.0f;
        moving = true;
    }
}

void Player::update(sf::RenderWindow& window, sf::Time delta)
{
    if (getRect().left < 0)
    {
        position.x = window.getSize().x - 10;
    }

    if (getRect().left + 10 > window.getSize().x) {
        position.x = 0;
    }

    if (!moving) {
        // stop moving
        acceleration.x = 0.0f;
        velocity.x /= 1.1f;
    } else {
        updateAnimation(delta);
    }

    velocity += acceleration * delta.asSeconds();

    // Limit vel
    velocity.x = static_cast<float>(fmin(5.8f, fmax(velocity.x, -5.8f)));
    velocity.y = static_cast<float>(fmin(9.8f, fmax(velocity.y, -9.8f)));

    // Update the ball position variables
    position += velocity;

    // Move the player
    this->sprite.setPosition(position);
}

void Player::draw(sf::RenderWindow& window, sf::Time delta) {
    // Draw this
    window.draw(this->sprite);
}

void Player::updateAnimation(sf::Time delta) {
    /* Update the animation */
    this->animationHandler.update(delta.asSeconds());

    /* Update the sprite */
    this->sprite.setTextureRect(this->animationHandler.bounds);
}
