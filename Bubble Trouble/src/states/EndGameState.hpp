//
// Created by pat on 17/05/18.
//

#ifndef BUBBLETROUBLE_ENDGAMESTATE_H
#define BUBBLETROUBLE_ENDGAMESTATE_H

#include "GameState.hpp"
#include "MenuGameState.hpp"

class EndGameState : public GameState {
public:
    explicit EndGameState(Game* game, int score);

    void handleEvents() override;
    void update(sf::Time delta) override;
    void draw(sf::Time delta) override;

private:
    sf::View view;
    sf::Text text;
};


#endif //BUBBLETROUBLE_ENDGAMESTATE_H
