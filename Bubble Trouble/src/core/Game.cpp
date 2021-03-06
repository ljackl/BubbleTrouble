//
// Created by pat on 18/04/18.
//

#include "Game.hpp"
#include "../states/SplashGameState.hpp"

Game::Game(int screenWidth, int screenHeight) {
    this->isRunning = true;

    this->loadTextures();

    this->window.create(sf::VideoMode(static_cast<unsigned int>(screenWidth),
                                                static_cast<unsigned int>(screenHeight),
                                                32), "Bubble Trouble Remastered");
    this->window.setFramerateLimit(60);

    this->background.setTexture(this->textureManager.getRef("background"));
    this->background.setScale(
            float(this->window.getSize().x) / float(this->background.getTexture()->getSize().x),
            float(this->window.getSize().y) / float(this->background.getTexture()->getSize().y));

    primaryFont.loadFromFile("resources/fonts/kenvector_future.ttf");
    secondaryFont.loadFromFile("resources/fonts/kenvector_future_thin.ttf");

}

Game::~Game() {
    while(!this->states.empty()) popState();
}

void Game::run() {
    sf::Clock clock;

    while (running())
    {
        sf::Time elapsed = clock.restart();

        if(peekState() == nullptr) continue;

        // Handle Events
        peekState()->handleEvents();

        // Update
        peekState()->update(elapsed);

        // Draw
        window.clear(sf::Color::Black);
        peekState()->draw(elapsed);
        window.display();
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
    //delete this->states.top();
    this->states.pop();
}

GameState *Game::peekState() {
    if(this->states.empty()) return nullptr;
    return this->states.top();
}

void Game::loadTextures() {
    textureManager.loadTexture("background", "resources/images/background.png");
    textureManager.loadTexture("ground", "resources/images/ground.png");
    textureManager.loadTexture("player", "resources/images/player.png");
    textureManager.loadTexture("player-walking", "resources/images/player-walking.png");
    textureManager.loadTexture("bubble", "resources/images/bubble.png");
    textureManager.loadTexture("bullet", "resources/images/bullet.png");

    textureManager.getRef("background").setSmooth(true);
    textureManager.getRef("player").setSmooth(true);
    textureManager.getRef("player-walking").setSmooth(true);
}
