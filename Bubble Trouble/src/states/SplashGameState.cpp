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

    sf::Vector2f vel;
    sf::Vector2f acl = sf::Vector2f(0.0f, 0.0f);
    for( int i = 0; i < 5; i++ ) {
        vel = sf::Vector2f(rand() % 10, rand() % 10);
        pos = sf::Vector2f(rand() % (game->window.getSize().x - 50) + 10, rand() % (game->window.getSize().y - 50) + 10);
        bubbles.push_back(new Bubble(pos, vel, acl, STATE_SPLASHSCREEN, POP_ONE, this->game->textureManager.getRef("bubble")));
    }

    text = sf::Text("Bubble Trouble Remastered", this->game->primaryFont, 11);
    text.setCharacterSize(22);
    text.setPosition(10, 10);
}

SplashGameState::~SplashGameState() {
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
