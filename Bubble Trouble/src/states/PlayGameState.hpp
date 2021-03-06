//
// Created by pat on 26/04/18.
//

#ifndef BUBBLETROUBLE_PLAYGAMESTATE_H
#define BUBBLETROUBLE_PLAYGAMESTATE_H

#include "GameState.hpp"
#include "MenuGameState.hpp"
#include "EndGameState.hpp"

#include "../core/Player.hpp"
#include "../core/Bubble.hpp"
#include "../core/Bullet.hpp"

#include <random>
#include <iostream>

class PlayGameState : public GameState {
public:
    explicit PlayGameState(Game* game);
    ~PlayGameState();

    void handleEvents() override;
    void update(sf::Time delta) override;
    void draw(sf::Time delta) override;

private:
    std::vector<Bubble*> bubbles;
    std::vector<Bullet*> bullets;
    Player player;

    sf::Sprite groundSprite;

    sf::View view;
    sf::Text text;

    int score = 0;

    bool wasFired = false;
    bool isFired = false;
    void fireBullet();

    bool isIntersecting(sf::FloatRect shape1, sf::FloatRect shape2);
};


#endif //BUBBLETROUBLE_PLAYGAMESTATE_H
