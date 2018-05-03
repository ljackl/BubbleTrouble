//
// Created by pat on 26/04/18.
//

#include "MenuGameState.hpp"

void MenuGameState::draw(sf::RenderWindow* window) {
    sf::Font font;
    font.loadFromFile("resources/fonts/PxPlus_IBM_EGA8.ttf");

    sf::Text text = sf::Text("Bubble Trouble Remastered\nMain Menu", font, 11);
    text.setCharacterSize(32);
    text.setPosition(window->getSize().x/2 - text.getGlobalBounds().width/2,
                     window->getSize().y/2 - text.getGlobalBounds().height/2);

    window->draw(text);
}

void MenuGameState::update() {

}

void MenuGameState::handleEvents(sf::RenderWindow *window, Game *game) {

}
