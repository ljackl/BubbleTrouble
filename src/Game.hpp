//
// Created by pat on 18/04/18.
//

#ifndef BUBBLETROUBLE_GAME_H
#define BUBBLETROUBLE_GAME_H

#ifdef _WIN32
#include "stdafx.h"
#endif

class GameState;

#include <vector>

#include <SFML/Graphics.hpp>
#include "Blob.hpp"
#include "states/GameState.hpp"

class Game {
private:
    sf::RenderWindow* window;
    sf::Font font;
    sf::Text text;

    int screenWidth;
    int screenHeight;
    bool isRunning;
    std::vector<GameState*> states;

    Blob blob = Blob(0, 0);

public:
    Game(int screenWidth, int screenHeight);
    ~Game();

    void init();

    bool running() { return isRunning; }

    void ChangeState(GameState* state);
    void PushState(GameState* state);
    void PopState();

    void handleEvents();
    void update();
    void draw();
};


#endif //BUBBLETROUBLE_GAME_H
