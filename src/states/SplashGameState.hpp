//
// Created by pat on 26/04/18.
//

#ifndef BUBBLETROUBLE_SPLASHGAMESTATE_H
#define BUBBLETROUBLE_SPLASHGAMESTATE_H

#include "GameState.hpp"
#include "MenuGameState.hpp"
#include "../Game.hpp"
#include "../Bubble.hpp"

class SplashGameState : public GameState {
public:
    SplashGameState();
    ~SplashGameState();

    void update(sf::RenderWindow* window, sf::Time delta) override;
    void draw(sf::RenderWindow* window) override;
    void handleEvents(sf::RenderWindow* window, Game* game) override;

private:
    std::vector<Bubble*> bubbles;

    sf::Font font;
    sf::Text text;
};


#endif //BUBBLETROUBLE_SPLASHGAMESTATE_H
