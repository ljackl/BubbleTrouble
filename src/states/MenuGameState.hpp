//
// Created by pat on 26/04/18.
//

#ifndef BUBBLETROUBLE_MENUGAMESTATE_H
#define BUBBLETROUBLE_MENUGAMESTATE_H

#ifdef _WIN32
#include "stdafx.h"
#endif

#include "GameState.hpp"
#include "PlayGameState.hpp"

#include <list>

class MenuGameState : public GameState {
public:
    enum MenuResult { Nothing, Exit, Play };

    struct MenuItem {
    public:
        sf::Rect<int> rect;
        MenuResult action;

        sf::RectangleShape button;
        sf::Text buttonText;
    };

    MenuGameState(Game* game);

    void handleEvents() override;
    void update(sf::Time delta) override;
    void draw(sf::Time delta) override;

private:
    sf::Text text;

    std::list<MenuItem> menuItems;

    sf::View view;
    MenuResult HandleClick(int x, int y);
};


#endif //BUBBLETROUBLE_MENUGAMESTATE_H
