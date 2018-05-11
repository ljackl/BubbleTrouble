//
// Created by pat on 18/04/18.
//

#ifndef BUBBLETROUBLE_GAME_H
#define BUBBLETROUBLE_GAME_H

#include <stack>
#include <SFML/Graphics.hpp>
#include "TextureManager.hpp"

class GameState;

class Game {
private:
    std::stack<GameState*> states;
    bool isRunning;

    void loadTextures();

public:
    sf::RenderWindow window;
    TextureManager textureManager;
    sf::Sprite background;
    sf::Font primaryFont;
    sf::Font secondaryFont;

    Game(int screenWidth, int screenHeight);
    ~Game();

    bool running() { return isRunning; }
    void end() { isRunning = false; }

    GameState* peekState();
    void changeState(GameState *state);
    void pushState(GameState *state);
    void popState();

    void run();
};


#endif //BUBBLETROUBLE_GAME_H
