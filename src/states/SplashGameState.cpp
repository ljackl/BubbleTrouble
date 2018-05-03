//
// Created by pat on 26/04/18.
//

#include "SplashGameState.hpp"
#include "MenuGameState.hpp"
#include "../Game.hpp"

void SplashGameState::draw(sf::RenderWindow *window) {
    sf::Font font;
    font.loadFromFile("resources/fonts/PxPlus_IBM_EGA8.ttf");

    sf::Text text = sf::Text("Bubble Trouble Remastered\nSplash Screen", font, 11);
    text.setCharacterSize(32);
    text.setPosition(window->getSize().x/2 - text.getGlobalBounds().width/2,
                     window->getSize().y/2 - text.getGlobalBounds().height/2);

    window->draw(text);
}

void SplashGameState::update() {

}

void SplashGameState::handleEvents(sf::RenderWindow* window, Game* game) {
    sf::Event event;

    while(window->pollEvent(event)) {
        if(event.type == sf::Event::Closed){
            window->close();
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        game->ChangeState(new MenuGameState());
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {

        window->close();
    }
}


