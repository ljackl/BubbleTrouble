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

void Game::init() {
    blob = Blob(640 / 2, 1);

    font.loadFromFile("resources/fonts/PxPlus_IBM_EGA8.ttf");

    text = sf::Text("Bubble Trouble Remastered",font,11);
    text.setCharacterSize(32);
    text.setPosition(window->getSize().x/2 - text.getGlobalBounds().width/2,
                     window->getSize().y/2 - text.getGlobalBounds().height/2);
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

void Game::draw() {
    window->clear(sf::Color::Black);

    states.back()->draw(window);

    //window->draw(text);
    window->draw(blob.getShape());
    window->display();
}

void Game::ChangeState(GameState *state) {
    if ( !states.empty() ) {
        states.pop_back();
    }

    states.push_back(state);
    //states.back()->Init();
}

void Game::PushState(GameState* state)
{
    states.push_back(state);
    //states.back()->Init();
}

void Game::PopState()
{
    if ( !states.empty() ) {
        states.pop_back();
    }
}
