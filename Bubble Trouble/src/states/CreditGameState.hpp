//
// Created by jack on 26/04/18.
//

#ifndef BUBBLETROUBLE_CREDITGAMESTATE_H
#define BUBBLETROUBLE_CREDITGAMESTATE_H

#include "GameState.hpp"
#include "MenuGameState.hpp"
#include "../core/Bubble.hpp"
#include <list>

class CreditGameState : public GameState {
public:
	enum MenuResult { Nothing, Exit, Back };

	struct MenuItem {
	public:
		sf::Rect<int> rect;
		MenuResult action;

		sf::RectangleShape button;
		sf::Text buttonText;
	};

	explicit CreditGameState(Game* game);
	~CreditGameState();

	void handleEvents() override;
	void update(sf::Time delta) override;
	void draw(sf::Time delta) override;

private:
    sf::View view;
    sf::Text title;
    sf::Text contributors;
    std::list<MenuItem> menuItems;

	std::vector<Bubble*> bubbles;

	MenuResult HandleClick(int x, int y);
};

#endif //BUBBLETROUBLE_CREDITGAMESTATE_H
