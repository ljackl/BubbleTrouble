//
// Created by pat on 26/04/18.
//

#include "MenuGameState.hpp"

MenuGameState::MenuGameState(Game* game) {
    this->game = game;

    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
    this->view.setSize(pos);
    pos *= 0.5f;
    this->view.setCenter(pos);

    text = sf::Text("Bubble Trouble Remastered\nMain Menu", this->game->primaryFont, 11);
    text.setCharacterSize(22);
    text.setPosition(10, 10);

    // Play button
    MenuItem playButton;
    playButton.action = Play;

    playButton.rect.left = 30;
    playButton.rect.top = game->window.getSize().y - 25 - 30;
    playButton.rect.width = 100;
    playButton.rect.height = 25;

    playButton.buttonText = sf::Text("Play", this->game->secondaryFont, 12);
    playButton.buttonText.setPosition(sf::Vector2f(playButton.rect.left + 10, playButton.rect.top + 1));
    playButton.buttonText.setFillColor(sf::Color(0, 0, 0));

    playButton.button.setSize(sf::Vector2f(playButton.rect.width, playButton.rect.height));
    playButton.button.setPosition(sf::Vector2f(playButton.rect.left, playButton.rect.top));

    menuItems.push_back(playButton);
}

void MenuGameState::handleEvents() {
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
                }
                break;
            }
            case sf::Event::MouseButtonReleased:
            {
                if (HandleClick(event.mouseButton.x,event.mouseButton.y) == Play) {
                    game->changeState(new PlayGameState(this->game));
                }
                break;
            }
            default: break;
        }
    }
}

void MenuGameState::update(sf::Time delta) {

}

void MenuGameState::draw(sf::Time delta) {
    this->game->window.setView(this->view);
    this->game->window.clear(sf::Color::Black);
    this->game->window.draw(this->game->background);

    for (auto &item : menuItems) {
        this->game->window.draw(item.button);
        this->game->window.draw(item.buttonText);
    }

    this->game->window.draw(text);
}

MenuGameState::MenuResult MenuGameState::HandleClick(int x, int y) {
    for (auto &item : menuItems) {
        if( y > item.rect.top && y < (item.rect.top + item.rect.height)) {
            return item.action;
        }
    }

    return Nothing;
}


