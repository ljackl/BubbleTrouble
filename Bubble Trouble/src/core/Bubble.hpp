//
// Created by pat on 18/04/18.
//

#ifndef BUBBLETROUBLE_BLOB_H
#define BUBBLETROUBLE_BLOB_H

#include <cmath>
#include <SFML/Graphics.hpp>
#include "GameEntity.hpp"

// TODO : https://stackoverflow.com/questions/18335861/why-is-enum-class-preferred-over-plain-enum#18335862
enum State
{
    STATE_SPLASHSCREEN,
    STATE_PLAY
};

enum PopState
{
    POP_ONE,
    POP_TWO,
    POP_THREE,
    POPPED
};

class Bubble : public GameEntity {
public:
    Bubble(float startX, float startY, State pState, sf::Texture& texture);
    Bubble(const Bubble& p);

    void handleEvents() override {}
    void update(sf::RenderWindow& window, sf::Time delta) override;
    void draw(sf::RenderWindow& window, sf::Time delta) override;

    void popBubble();
    bool isPopped() { return popState == POPPED; }

    void reboundSides();

private:
    void reboundBottomOrTop();

    State state;
    PopState popState = POP_ONE;
};

#endif //BUBBLETROUBLE_BLOB_H
