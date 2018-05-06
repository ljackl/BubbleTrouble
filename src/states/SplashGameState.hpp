//
// Created by pat on 26/04/18.
//

#ifndef BUBBLETROUBLE_SPLASHGAMESTATE_H
#define BUBBLETROUBLE_SPLASHGAMESTATE_H

#include "GameState.hpp"
#include "../core/Bubble.hpp"

class SplashGameState : public GameState {
public:
    explicit SplashGameState(Game* game);
    ~SplashGameState();

    void handleEvents() override;
    void update(sf::Time delta) override;
    void draw(sf::Time delta) override;

private:
    std::vector<Bubble*> bubbles;

    sf::View view;
    sf::Font font;
    sf::Text text;
};


#endif //BUBBLETROUBLE_SPLASHGAMESTATE_H
