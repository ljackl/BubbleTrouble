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

void PlayGameState::draw(sf::RenderWindow *window) {
    for (auto &item : bubbles) {
        item->draw(window);
    }

    // Draw Bullets
    for (auto &item : bullets) {
        item->draw(window);
    }

    player.draw(window);

    text.setPosition(window->getSize().x/2 - text.getGlobalBounds().width/2,
                     window->getSize().y/2 - text.getGlobalBounds().height/2);

    window->draw(text);
}

void PlayGameState::fireBullet() {
    bullets.push_back(new Bullet(player.getPosition()));
}
