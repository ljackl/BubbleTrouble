//
// Created by pat on 26/04/18.
//

#include "PlayGameState.hpp"

PlayGameState::PlayGameState() {
    for( int i = 0; i < 10; i++ ) {
        bubbles.push_back(new Bubble(rand() % 100, rand() % 100, STATE_PLAY));
    }

    font.loadFromFile("resources/fonts/PxPlus_IBM_EGA8.ttf");

    text = sf::Text("Bubble Trouble Remastered\nPlaying",font,11);
    text.setCharacterSize(32);

    // Background loading
    backgroundtexture.loadFromFile("resources/images/background.png");
    backgroundSprite.setTexture(backgroundtexture);

    // Ground loading
    groundtexture.loadFromFile("resources/images/chocoMid.png");
    groundtexture.setRepeated(true);
    groundSprite.setTexture(groundtexture);
}

void PlayGameState::draw(sf::RenderWindow *window) {
    // TODO
    // Implementing view for window size independent drawing
    // https://www.sfml-dev.org/tutorials/2.1/graphics-view.php

    // Background
    backgroundSprite.setPosition(sf::Vector2f(0, 0));
    backgroundSprite.setScale(
            window->getSize().x / backgroundSprite.getLocalBounds().width,
            window->getSize().y / backgroundSprite.getLocalBounds().height);

    // Ground
    groundSprite.setTextureRect(sf::IntRect(0, 0, window->getSize().x, groundtexture.getSize().y));
    groundSprite.setPosition(sf::Vector2f(0, window->getSize().y - groundSprite.getLocalBounds().height));

    window->draw(backgroundSprite);
    window->draw(groundSprite);

    text.setPosition(window->getSize().x/2 - text.getGlobalBounds().width/2,
                     window->getSize().y/2 - text.getGlobalBounds().height/2);

    window->draw(text);

    for (auto &item : bubbles) {
        window->draw(item->getShape());
    }

    window->draw(player.getShape());

    // Draw Bullets
    for (auto &item : bullets) {
        item->draw(window);
    }
}

void PlayGameState::handleEvents(sf::RenderWindow *window, Game *game) {
    sf::Event event;

    while(window->pollEvent(event)) {
        if(event.type == sf::Event::Closed){
            window->close();
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        game->popState();
    }

    player.handleEvents();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        fireBullet();
    }
}

void PlayGameState::update(sf::RenderWindow *window, sf::Time delta) {
    player.update(*window, delta);

    for (auto &item : bullets) {
        item->update(*window, delta);
    }

    for (auto &item : bubbles) {
        item->update(*window, delta);
    }


}

void PlayGameState::fireBullet() {
    bullets.push_back(new Bullet(player.getPosition()));
}
