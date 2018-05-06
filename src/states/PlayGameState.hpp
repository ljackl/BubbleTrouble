//
// Created by pat on 26/04/18.
//

#ifndef BUBBLETROUBLE_PLAYGAMESTATE_H
#define BUBBLETROUBLE_PLAYGAMESTATE_H

#include "GameState.hpp"
#include "MenuGameState.hpp"
#include "../Game.hpp"
#include "../Player.hpp"

class PlayGameState : public GameState {
public:
    PlayGameState();

    void update(sf::RenderWindow* window, sf::Time delta) override;
    void draw(sf::RenderWindow* window) override;
    void handleEvents(sf::RenderWindow* window, Game* game) override;

private:
    sf::Texture backgroundtexture;
    sf::Sprite backgroundSprite;

    sf::Texture groundtexture;
    sf::Sprite groundSprite;
    std::vector<Bubble*> bubbles;
    Player player = Player(50, 150);

    sf::Font font;
    sf::Text text;
};


#endif //BUBBLETROUBLE_PLAYGAMESTATE_H
