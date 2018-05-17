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

    sf::Vector2f targetSize(30.0f, 40.0f);
    this->sprite.setOrigin(sf::Vector2f(0.0f, 0.0f));
    this->sprite.setTexture(texture);

    this->sprite.setScale(
            targetSize.x / this->sprite.getLocalBounds().width,
            targetSize.y / this->sprite.getLocalBounds().height);

    this->position.y -= this->sprite.getGlobalBounds().height;

    this->sprite.setPosition(position);
    /*this->animationHandler.frameSize = sf::IntRect(0, 0, 100, 100);
    for(auto animation : animations)
    {
        this->animationHandler.addAnimimatin(animation);
    }
    this->animationHandler.update(0.0f);*/
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
    /* Change the sprite to reflect the tile variant */
    //this->animationHandler.changeAnim(1);

    /* Update the animation */
    //this->animationHandler.update(delta.asSeconds());

    /* Update the sprite */
    //this->sprite.setTextureRect(this->animationHandler.bounds);

    // Draw this
    window.draw(this->sprite);
}
