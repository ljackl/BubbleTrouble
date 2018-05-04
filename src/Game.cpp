//
// Created by pat on 18/04/18.
//

#include "Game.hpp"

Game::Game(int screenWidth, int screenHeight) : screenWidth(screenWidth),screenHeight(screenHeight) {
    isRunning = true;
    window = new sf::RenderWindow(sf::VideoMode(static_cast<unsigned int>(screenWidth),
                                                static_cast<unsigned int>(screenHeight),
                                                32), "Bubble Trouble Remastered");

    window->setFramerateLimit(60);
}

Game::~Game() {
    delete window;
}

void Game::handleEvents() {
    states.back()->handleEvents(window, this);

    sf::Event event;

    while(window->pollEvent(event)) {
        if(event.type == sf::Event::Closed){
            window->close();
            isRunning = false;
        }
    }
}

void Game::update(sf::Time delta) {
    states.back()->update(window, delta);
}

void Game::draw() {
    window->clear(sf::Color::Black);

    states.back()->draw(window);

    window->display();
}

void Game::changeState(GameState *state) {
    if ( !states.empty() ) {
        states.pop_back();
    }

    states.push_back(state);
}

void Game::pushState(GameState *state)
{
    states.push_back(state);
}

void Game::popState()
{
    GameState* oldState = states.back();
    if ( !states.empty() ) {
        states.pop_back();
    }

    delete oldState;
}
