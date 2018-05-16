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
	explicit CreditGameState(Game* game);
	~CreditGameState();
	struct MenuItem {
	public:
		sf::Rect<int> rect;
		MenuResult action;

		sf::RectangleShape button;
		sf::Text buttonText;
	};
	void handleEvents() override;
	void update(sf::Time delta) override;
	void draw(sf::Time delta) override;

private:
	std::vector<Bubble> bubbles;
	std::list<MenuItem> menuItems;
	MenuResult HandleClick(int x, int y);
	sf::View view;
	sf::Text title;
	sf::Text contributors;
};

#endif //BUBBLETROUBLE_CREDITGAMESTATE_H
