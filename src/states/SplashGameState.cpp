//
// Created by pat on 26/04/18.
//

#include "SplashGameState.hpp"

SplashGameState::SplashGameState() {

    for( int i = 0; i < 10; i++ ) {
        bubbles.push_back(new Bubble(rand() % 100, rand() % 100, STATE_SPLASHSCREEN));
    }

    font.loadFromFile("resources/fonts/PxPlus_IBM_EGA8.ttf");

    text = sf::Text("Bubble Trouble Remastered",font,11);
    text.setCharacterSize(32);
}

SplashGameState::~SplashGameState() {
    for (auto &item : bubbles) {
        delete item;
    }
    bubbles.clear();
}

void SplashGameState::handleEvents(sf::RenderWindow* window, Game* game) {
    sf::Event event;

    while(window->pollEvent(event)) {
        if(event.type == sf::Event::Closed){
            window->close();
            game->end();
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        game->changeState(new MenuGameState());
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        window->close();
        game->end();
    }
}

void SplashGameState::update(sf::RenderWindow *window) {
    for (auto &item : bubbles) {
        item->update(*window);
    }
}

void SplashGameState::draw(sf::RenderWindow *window) {
    for (auto &item : bubbles) {
        window->draw(item->getShape());
    }

    text.setPosition(window->getSize().x/2 - text.getGlobalBounds().width/2,
                     window->getSize().y/2 - text.getGlobalBounds().height/2);

    window->draw(text);
}
