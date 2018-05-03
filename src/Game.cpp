//
// Created by pat on 18/04/18.
//

#include "Game.hpp"

Game::Game(int screenWidth, int screenHeight) : screenWidth(screenWidth),screenHeight(screenHeight) {
    isRunning = true;
    window = new sf::RenderWindow(sf::VideoMode(640,480,32),"Bubble Trouble Remastered");
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

void Game::update() {
    states.back()->update();
}

void Game::draw() {
    window->clear(sf::Color::Black);

    states.back()->draw(window);

    window->display();
}

void Game::ChangeState(GameState *state) {
    if ( !states.empty() ) {
        states.pop_back();
    }

    states.push_back(state);
}

void Game::PushState(GameState* state)
{
    states.push_back(state);
}

void Game::PopState()
{
    if ( !states.empty() ) {
        states.pop_back();
    }
}
