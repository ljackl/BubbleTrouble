//
// Created by pat on 6/05/18.
//

#include "Player.hpp"

Player::Player(float startX, float startY, sf::Texture& texture, const std::vector<Animation>& animations) {
    position.x = startX;
    position.y = startY;

    velocity.x = 0.0f;
    velocity.y = 0.0f;

    acceleration.x = 0.0f;
    acceleration.y = 0.0f;

    shape.setSize(sf::Vector2f(10, 10));
    shape.setPosition(position);

    this->sprite.setOrigin(sf::Vector2f(0.0f, 0.0f));
    this->sprite.setTexture(texture);
    this->animationHandler.frameSize = sf::IntRect(0, 0, 100, 100);
    for(auto animation : animations)
    {
        this->animationHandler.addAnimimatin(animation);
    }
    this->animationHandler.update(0.0f);
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
}

void Player::update(sf::RenderWindow& window, sf::Time delta)
{
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
    shape.setPosition(position);
}

void Player::draw(sf::RenderWindow& window, sf::Time delta) {
    // Draw this
    window.draw(getShape());

    /* Change the sprite to reflect the tile variant */
    //this->animationHandler.changeAnim(1);

    /* Update the animation */
    this->animationHandler.update(delta.asSeconds());

    /* Update the sprite */
    this->sprite.setTextureRect(this->animationHandler.bounds);


    this->sprite.setPosition(position);
    /* Draw the tile */
    window.draw(this->sprite);
}
