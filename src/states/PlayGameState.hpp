//
// Created by pat on 26/04/18.
//

#ifndef BUBBLETROUBLE_PLAYGAMESTATE_H
#define BUBBLETROUBLE_PLAYGAMESTATE_H

#include "GameState.hpp"
#include "MenuGameState.hpp"
#include "../Game.hpp"

class PlayGameState : public GameState {
public:
    PlayGameState();

    void update(sf::RenderWindow* window) override;
    void draw(sf::RenderWindow* window) override;
    void handleEvents(sf::RenderWindow* window, Game* game) override;

private:
    std::vector<Bubble*> bubbles;

    sf::Font font;
    sf::Text text;
};


#endif //BUBBLETROUBLE_PLAYGAMESTATE_H
