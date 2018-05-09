//
// Created by pat on 26/04/18.
//

#include "PlayGameState.hpp"

PlayGameState::PlayGameState(Game* game) {
    this->game = game;

    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
    this->view.setSize(pos);
    pos *= 0.5f;
    this->view.setCenter(pos);

    for( int i = 0; i < 10; i++ ) {
        bubbles.push_back(new Bubble(rand() % 100, rand() % 100, STATE_PLAY));
    }

    text = sf::Text("Bubble Trouble Remastered\nPlaying", this->game->primaryFont, 11);
    text.setCharacterSize(22);
    text.setPosition(10, 10);

    // Ground loading
    this->game->textureManager.getRef("ground").setRepeated(true);
    groundSprite.setTexture(this->game->textureManager.getRef("ground"));

    Animation staticAnim(0, 0, 1.0f);
    player = Player(50, 50, this->game->textureManager.getRef("player"), { staticAnim });
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
                    // TODO: Adds states infinitum on top of each other
                    this->game->pushState(new MenuGameState(this->game));
                } else if (event.key.code == sf::Keyboard::Space) {
                    fireBullet();
                }
                break;
            }
            default: break;
        }
    }
    player.handleEvents();
}

void PlayGameState::update(sf::Time delta) {
    player.update(this->game->window, delta);

    for (auto &item : bullets) {
        item->update(this->game->window, delta);
    }

    for (auto &item : bubbles) {
        item->update(this->game->window, delta);
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
    bullets.push_back(new Bullet(player.getPosition()));
}
