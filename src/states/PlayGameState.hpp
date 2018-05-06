//
// Created by pat on 26/04/18.
//

#ifndef BUBBLETROUBLE_PLAYGAMESTATE_H
#define BUBBLETROUBLE_PLAYGAMESTATE_H

#include "GameState.hpp"
#include "MenuGameState.hpp"

#include "../core/Player.hpp"
#include "../core/Bubble.hpp"
#include "../core/Bullet.hpp"

class PlayGameState : public GameState {
public:
    PlayGameState();

    void update(sf::RenderWindow* window, sf::Time delta) override;
    void draw(sf::RenderWindow* window) override;
    void handleEvents(sf::RenderWindow* window, Game* game) override;

private:
    std::vector<Bubble*> bubbles;
    std::vector<Bullet*> bullets;
    Player player = Player(50, 150);

    sf::Font font;
    sf::Text text;

    void fireBullet();
};


#endif //BUBBLETROUBLE_PLAYGAMESTATE_H
