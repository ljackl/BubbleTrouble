//
// Created by pat on 26/04/18.
//

#include "SplashGameState.hpp"
#include "../Game.hpp"

SplashGameState::SplashGameState() {
    blob = Blob(640 / 2, 1);

    font.loadFromFile("resources/fonts/PxPlus_IBM_EGA8.ttf");

    text = sf::Text("Bubble Trouble Remastered",font,11);
    text.setCharacterSize(32);
}

void SplashGameState::draw(sf::RenderWindow *window) {
    window->draw(blob.getShape());

    text.setPosition(window->getSize().x/2 - text.getGlobalBounds().width/2,
                     window->getSize().y/2 - text.getGlobalBounds().height/2);

    window->draw(text);
}

void SplashGameState::update() {
    if (blob.getPosition().top > 480)
    {
        blob.reboundBatOrTop();
    }

    if (blob.getPosition().left < 0 || blob.getPosition().left + 10 > 640)
    {
        blob.reboundSides();
    }

    if (blob.getPosition().top < 0)
    {
        blob.reboundBatOrTop();

    }

    blob.update();
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
        //game->ChangeState(new MenuGameState());
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {

        window->close();
    }
}
