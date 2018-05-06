//
// Created by pat on 18/04/18.
//

#include "Game.hpp"
#include "../states/SplashGameState.hpp"

Game::Game(int screenWidth, int screenHeight) {
    isRunning = true;

    window = new sf::RenderWindow(sf::VideoMode(static_cast<unsigned int>(screenWidth),
                                                static_cast<unsigned int>(screenHeight),
                                                32), "Bubble Trouble Remastered");

    window->setFramerateLimit(60);
}

Game::~Game() {
    while(!this->states.empty()) popState();

    delete window;
}

void Game::run() {
    sf::Clock clock;
    changeState(new SplashGameState());

    while (running())
    {
        sf::Time elapsed = clock.restart();

        if(peekState() == nullptr) continue;

        // Handle Events
        peekState()->handleEvents(window, this);

        // Update
        peekState()->update(window, elapsed);

        // Draw
        window->clear(sf::Color::Black);
        peekState()->draw(window);
        window->display();
    }
}

void Game::changeState(GameState *state) {
    if(!this->states.empty())
        popState();

    pushState(state);
}

void Game::pushState(GameState *state)
{
    this->states.push(state);
}

void Game::popState()
{
    delete this->states.top();
    this->states.pop();
}

GameState *Game::peekState() {
    if(this->states.empty()) return nullptr;
    return this->states.top();
}
