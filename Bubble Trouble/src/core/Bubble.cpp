//
// Created by pat on 18/04/18.
//

#include "Bubble.hpp"

// This the constructor and it is called when we create an object
Bubble::Bubble(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f acceleration, State state, PopState popState, sf::Texture& texture) {
    this->position = position;
    this->velocity = velocity;
    this->acceleration = acceleration;
    this->state = state;
    this->popState = popState;


    sf::Vector2f targetSize(30.0f, 30.0f);
    this->sprite.setOrigin(sf::Vector2f(0.0f, 0.0f));
    this->sprite.setTexture(texture);

    this->sprite.setScale(
            targetSize.x / this->sprite.getLocalBounds().width,
            targetSize.y / this->sprite.getLocalBounds().height);

    this->sprite.setPosition(position);
}

Bubble::Bubble(const Bubble &bubble) {
    this->position = bubble.position;
    this->velocity = bubble.velocity;
    this->acceleration = bubble.acceleration;
    this->state = bubble.state;
    this->popState = bubble.popState;
    this->sprite = bubble.sprite;
}

void Bubble::reboundSides() {
    //position.x -= (velocity.x * 30);
    velocity.x *= -1;
    acceleration.x *= -1;
}

void Bubble::reboundBottomOrTop() {
    //position.y -= (velocity.y * 30);
    velocity.y *= -1;
}

void Bubble::bounce() {
    velocity.y = -9.8f;
    acceleration.y = -20.2f;
}

void Bubble::update(sf::RenderWindow& window, sf::Time delta) {
    switch (state) {
        case STATE_SPLASHSCREEN:
            if (sprite.getGlobalBounds().left < 0 || sprite.getGlobalBounds().left + sprite.getGlobalBounds().width > window.getSize().x) {
                reboundSides();
            }
            if (sprite.getGlobalBounds().top < 0 || sprite.getGlobalBounds().top + sprite.getGlobalBounds().height > window.getSize().y) {
                reboundBottomOrTop();
            }
            break;

        case STATE_PLAY:
            // https://gamedev.stackexchange.com/questions/121389/how-i-can-make-better-jump-to-my-game-c-sfml
            if (sprite.getGlobalBounds().left < 0 || sprite.getGlobalBounds().left + sprite.getGlobalBounds().width > window.getSize().x) {
                reboundSides();
            }
            if (sprite.getGlobalBounds().top > window.getSize().y / 2) {
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
    sprite.setPosition(position);
}

void Bubble::draw(sf::RenderWindow& window, sf::Time delta) {
    // Draw this
    window.draw(sprite);
}

void Bubble::popBubble() {
    switch (popState) {
        case POP_ONE:
            popState = POP_TWO;
            sprite.scale(sf::Vector2f(0.7f, 0.7f));
            break;

        case POP_TWO:
            popState = POP_THREE;
            sprite.scale(sf::Vector2f(0.7f, 0.7f));
            break;

        case POP_THREE:
            popState = POPPED;
            break;

        case POPPED:break;
    }
}
