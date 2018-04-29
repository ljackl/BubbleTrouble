//
// Created by pat on 26/04/18.
//

#ifndef BUBBLETROUBLE_SETTINGSGAMESTATE_H
#define BUBBLETROUBLE_SETTINGSGAMESTATE_H

#include "GameState.hpp"

class SettingsGameState : public GameState {
public:
    void update() override;
    void draw(sf::RenderWindow* window) override;
    void handleEvents(sf::RenderWindow* window, Game* game) override;
};


#endif //BUBBLETROUBLE_SETTINGSGAMESTATE_H
