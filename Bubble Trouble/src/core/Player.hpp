//
// Created by pat on 6/05/18.
//

#ifndef BUBBLETROUBLE_PLAYER_H
#define BUBBLETROUBLE_PLAYER_H

#include <cmath>
#include <SFML/Graphics.hpp>
#include "GameEntity.hpp"

class Player : public GameEntity {
private:
    bool moving = false;

public:
    Player() {}
    Player(sf::Vector2f position, sf::Texture& texture, const std::vector<Animation>& animations);

    void handleEvents() override;
    void update(sf::RenderWindow& window, sf::Time delta) override;
    void draw(sf::RenderWindow& window, sf::Time delta) override;
};


#endif //BUBBLETROUBLE_PLAYER_H
