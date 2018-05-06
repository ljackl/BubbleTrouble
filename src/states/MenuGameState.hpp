//
// Created by pat on 26/04/18.
//

#ifndef BUBBLETROUBLE_MENUGAMESTATE_H
#define BUBBLETROUBLE_MENUGAMESTATE_H

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

    MenuGameState();

    void update(sf::RenderWindow* window, sf::Time delta) override;
    void draw(sf::RenderWindow* window) override;
    void handleEvents(sf::RenderWindow* window, Game* game) override;

private:
    sf::Font font;
    sf::Text text;

    std::list<MenuItem> menuItems;

    MenuResult HandleClick(int x, int y);
};


#endif //BUBBLETROUBLE_MENUGAMESTATE_H
