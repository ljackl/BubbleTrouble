//
// Created by pat on 17/05/18.
//

#include "EndGameState.hpp"

EndGameState::EndGameState(Game *game, int score) {
    this->game = game;

    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
    this->view.setSize(pos);
    pos *= 0.5f;
    this->view.setCenter(pos);

    text = sf::Text("GAME OVER\n SCORE: " + std::to_string(score) , this->game->primaryFont, 11);
    text.setCharacterSize(22);
    text.setPosition(10, 10);
}

void EndGameState::handleEvents() {
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
                } else if (event.key.code == sf::Keyboard::Space) {
                    this->game->changeState(new MenuGameState(this->game));
                }
                break;
            }
            default: break;
        }
    }
}

void EndGameState::update(sf::Time delta) {
    // Nothing here
}

void EndGameState::draw(sf::Time delta) {
    this->game->window.setView(this->view);
    this->game->window.clear(sf::Color::Black);
    this->game->window.draw(this->game->background);
    this->game->window.draw(text);
}
