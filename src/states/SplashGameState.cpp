//
// Created by pat on 26/04/18.
//

#include "SplashGameState.hpp"

SplashGameState::SplashGameState(Game* game) {
    this->game = game;

    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
    this->view.setSize(pos);
    pos *= 0.5f;
    this->view.setCenter(pos);

    for( int i = 0; i < 10; i++ ) {
        bubbles.push_back(new Bubble(rand() % 100, rand() % 100, STATE_SPLASHSCREEN));
    }

    font.loadFromFile("resources/fonts/PxPlus_IBM_EGA8.ttf");

    text = sf::Text("Bubble Trouble Remastered",font,11);
    text.setCharacterSize(32);
    text.setPosition(game->window.getSize().x/2 - text.getGlobalBounds().width/2,
                     game->window.getSize().y/2 - text.getGlobalBounds().height/2);
}

SplashGameState::~SplashGameState() {
    for (auto &item : bubbles) {
        delete item;
    }
    bubbles.clear();
}

void SplashGameState::handleEvents() {
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
                    this->game->window.close();
                    this->game->end();
                } else if (event.key.code == sf::Keyboard::Space) {
                    this->game->changeState(new MenuGameState(this->game));
                }
                break;
            }
            default: break;
        }
    }
}

void SplashGameState::update(sf::Time delta) {
    for (auto &item : bubbles) {
        item->update(game->window, delta);
    }
}

void SplashGameState::draw(sf::Time delta) {
    this->game->window.setView(this->view);
    this->game->window.clear(sf::Color::Black);
    this->game->window.draw(this->game->background);

    for (auto &item : bubbles) {
        item->draw(this->game->window, delta);
    }

    this->game->window.draw(text);
}
