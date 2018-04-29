//
// Created by pat on 18/04/18.
//

#ifndef BUBBLETROUBLE_GAME_H
#define BUBBLETROUBLE_GAME_H

#ifdef _WIN32
#include "stdafx.h"
#endif

#include <SFML/Graphics.hpp>
#include "Blob.hpp"

class Game {
private:
    sf::RenderWindow* window;
    sf::Font font;
    sf::Text text;

    bool isRunning;
    Blob blob = Blob(0, 0);

public:
    Game();
    ~Game();

    void init();

    bool running() { return isRunning; }

    void handleEvents();
    void update();
    void draw();
};


#endif //BUBBLETROUBLE_GAME_H
