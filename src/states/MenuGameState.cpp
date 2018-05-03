//
// Created by pat on 26/04/18.
//

#include "MenuGameState.hpp"

MenuGameState::MenuGameState() {
    font.loadFromFile("resources/fonts/PxPlus_IBM_EGA8.ttf");

    text = sf::Text("Bubble Trouble Remastered\nMain Menu",font,11);
    text.setCharacterSize(32);

    // Play button
    MenuItem playButton;
    playButton.action = Play;

    playButton.rect.left = 30;
    playButton.rect.top = 40;
    playButton.rect.width = 100;
    playButton.rect.height = 25;

    playButton.buttonText = sf::Text("Play", font, 16);
    playButton.buttonText.setPosition(sf::Vector2f(playButton.rect.left + 10, playButton.rect.top + 1));
    playButton.buttonText.setFillColor(sf::Color(0, 0, 0));

    playButton.button.setSize(sf::Vector2f(playButton.rect.width, playButton.rect.height));
    playButton.button.setPosition(sf::Vector2f(playButton.rect.left, playButton.rect.top));

    menuItems.push_back(playButton);
}

void MenuGameState::handleEvents(sf::RenderWindow *window, Game *game) {
    sf::Event event;

    while(window->pollEvent(event)) {
        if(event.type == sf::Event::Closed){
            window->close();
            game->end();
        }

        if(event.type == sf::Event::MouseButtonReleased && HandleClick(event.mouseButton.x,event.mouseButton.y) == Play)
        {
            game->pushState(new PlayGameState());
        }
    }
}

void MenuGameState::update(sf::RenderWindow* window) {

}

void MenuGameState::draw(sf::RenderWindow* window) {
    text.setPosition(window->getSize().x/2 - text.getGlobalBounds().width/2,
                     window->getSize().y/2 - text.getGlobalBounds().height/2);

    for (auto &item : menuItems) {
        window->draw(item.button);
        window->draw(item.buttonText);
    }

    window->draw(text);
}

MenuGameState::MenuResult MenuGameState::HandleClick(int x, int y) {
    for (auto &item : menuItems) {
        if( y > item.rect.top && y < (item.rect.top + item.rect.height)) {
            return item.action;
        }
    }

    return Nothing;
}


