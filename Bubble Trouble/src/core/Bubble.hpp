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
    Bubble(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f acceleration, State State, PopState popState, sf::Texture& texture);
    Bubble(const Bubble &bubble);

    void handleEvents() override {}
    void update(sf::RenderWindow& window, sf::Time delta) override;
    void draw(sf::RenderWindow& window, sf::Time delta) override;

    void popBubble();
    bool isPopped() { return popState == POPPED; }

    void reboundSides();

private:
    void reboundBottomOrTop();

    State state;
    PopState popState;
};

#endif //BUBBLETROUBLE_BLOB_H
