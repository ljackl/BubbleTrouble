//
// Created by pat on 18/04/18.
//
#include "stdafx.h"

#include <iostream>
#include "Game.hpp"

Game::Game()
{}

Game::~Game()
{}

void Game::init() {
    isRunning = true;
    blob = Blob(640 / 2, 1);

    window = new sf::RenderWindow(sf::VideoMode(640,480,32),"Bubble Trouble Remastered");
    //if (window->isOpen()) std::cout << "Here!" << std::endl;

    font.loadFromFile("resources/fonts/PxPlus_IBM_EGA8.ttf");

    text = sf::Text("Bubble Trouble Remastered",font,11);
    text.setCharacterSize(32);
    text.setPosition(window->getSize().x/2 - text.getGlobalBounds().width/2,
                     window->getSize().y/2 - text.getGlobalBounds().height/2);
}

void Game::handleEvents() {
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
    window->draw(text);
    window->draw(blob.getShape());
    window->display();
}
