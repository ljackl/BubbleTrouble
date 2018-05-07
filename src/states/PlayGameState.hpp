//
// Created by pat on 26/04/18.
//

#ifndef BUBBLETROUBLE_PLAYGAMESTATE_H
#define BUBBLETROUBLE_PLAYGAMESTATE_H

#ifdef _WIN32
#include "stdafx.h"
#endif

#include "GameState.hpp"
#include "MenuGameState.hpp"

#include "../core/Player.hpp"
#include "../core/Bubble.hpp"
#include "../core/Bullet.hpp"

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
    sf::Font font;
    sf::Text text;

    void fireBullet();
};


#endif //BUBBLETROUBLE_PLAYGAMESTATE_H
