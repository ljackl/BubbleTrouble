//
// Created by pat on 26/04/18.
//

#include <iostream>
#include "PlayGameState.hpp"

PlayGameState::PlayGameState(Game* game) {
    this->game = game;

    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
    this->view.setSize(pos);
    pos *= 0.5f;
    this->view.setCenter(pos);

    text = sf::Text("Bubble Trouble Remastered\nPlaying", this->game->primaryFont, 11);
    text.setCharacterSize(22);
    text.setPosition(10, 10);

    // Ground loading
    this->game->textureManager.getRef("ground").setRepeated(true);
    groundSprite.setTexture(this->game->textureManager.getRef("ground"));

    // Player Creation
    Animation staticAnim(0, 0, 1.0f);
    player = Player(50, game->window.getSize().y - 40, this->game->textureManager.getRef("player"), { staticAnim });

    // Bubble Creation
    sf::Vector2f vel = sf::Vector2f(0.0f, 0.0f);
    sf::Vector2f acl = sf::Vector2f(3.2f, 9.8f);
    for( int i = 0; i < 2; i++ ) {
        pos = sf::Vector2f(rand() % game->window.getSize().x - 10, rand() % 100);
        bubbles.push_back(new Bubble(pos, vel, acl, STATE_PLAY, POP_ONE, this->game->textureManager.getRef("bubble")));
    }
}

PlayGameState::~PlayGameState() {
    for (auto &item : bubbles) {
        delete item;
    }
    bubbles.clear();

    for (auto &item : bullets) {
        delete item;
    }
    bullets.clear();
}

void PlayGameState::handleEvents() {
    sf::Event event;

    while(this->game->window.pollEvent(event))
    {
        switch(event.type)
        {
            /* Close the window */
            case sf::Event::Closed:
            {
                this->game->window.close();
                this->game->end();
                break;
            }
                /* Resize the window */
            case sf::Event::Resized:
            {
                this->view.setSize(event.size.width, event.size.height);
                this->game->background.setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, 0)));
                this->game->background.setScale(
                        float(event.size.width) / float(this->game->background.getTexture()->getSize().x),
                        float(event.size.height) / float(this->game->background.getTexture()->getSize().y));
                break;
            }
            case sf::Event::KeyPressed:
            {
                if (event.key.code == sf::Keyboard::Escape) {
                    this->game->changeState(new MenuGameState(this->game));
                }
                break;
            }
            default: break;
        }
    }

    isFired = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
    if (!isFired && wasFired) {
        fireBullet();
    }

    wasFired = isFired;

    player.handleEvents();
}

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> dis(0, 400);
void PlayGameState::update(sf::Time delta) {
    player.update(this->game->window, delta);

    for (auto &bullet : bullets) {
        // Update bullet
        bullet->update(this->game->window, delta);
        // Remove if out of frame
        if (bullet->isOutOfYFrame())
            bullets.erase(std::remove(bullets.begin(), bullets.end(), bullet), bullets.end());
    }

    for (auto &bubble : bubbles) {
        // Update bubble
        bubble->update(this->game->window, delta);
        // Check if player hit
        if (isIntersecting(bubble->getRect(), player.getRect()))
            this->game->changeState(new MenuGameState(this->game));
        // If popped remove
        if (bubble->isPopped())
            bubbles.erase(std::remove(bubbles.begin(), bubbles.end(), bubble), bubbles.end());
    }

    // Check for bubble bullet collisions
    for (auto &bullet : bullets) {
        for (auto &bubble : bubbles) {
            if (isIntersecting(bullet->getRect(), bubble->getRect())) {
                // Remove the bullet
                bullets.erase(std::remove(bullets.begin(), bullets.end(), bullet), bullets.end());

                // Create double bubble & Pop bubble
                bubble->popBubble();
                this->bubbles.push_back(new Bubble(*bubble));
                bubble->reboundSides();

                // Update score
                score++;
                text.setString("Score: " + std::to_string(score));

                // Kill loop
                break;
            }
        }
    }

    // Randomly create new bubbles
    auto number = static_cast<int>(dis(gen));
    if (number == 1) {
        sf::Vector2f pos = sf::Vector2f(rand() % this->game->window.getSize().x - 10, rand() % 100);
        sf::Vector2f vel = sf::Vector2f(0.0f, 0.0f);
        sf::Vector2f acl = sf::Vector2f(3.2f, 9.8f);
        this->bubbles.push_back(new Bubble(pos, vel, acl, STATE_PLAY, POP_ONE, this->game->textureManager.getRef("bubble")));
    }
}

void PlayGameState::draw(sf::Time delta) {
    this->game->window.setView(this->view);
    this->game->window.clear(sf::Color::Black);
    this->game->window.draw(this->game->background);

    // Ground
    groundSprite.setTextureRect(sf::IntRect(0, 0, this->game->window.getSize().x, this->game->textureManager.getRef("ground").getSize().y));
    groundSprite.setPosition(sf::Vector2f(0, this->game->window.getSize().y - groundSprite.getLocalBounds().height));
    this->game->window.draw(groundSprite);

    this->game->window.draw(text);

    // Draw Bubbles
    for (auto &item : bubbles) {
        item->draw(this->game->window, delta);
    }

    // Draw Bullets
    for (auto &item : bullets) {
        item->draw(this->game->window, delta);
    }

    // Draw Player
    player.draw(this->game->window, delta);

}

void PlayGameState::fireBullet() {
    bullets.push_back(new Bullet(player.getRect(), this->game->textureManager.getRef("bullet")));
}

bool PlayGameState::isIntersecting(sf::FloatRect shape1, sf::FloatRect shape2) {
    return shape1.intersects(shape2);
}
