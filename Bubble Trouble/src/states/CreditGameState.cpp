//
// Created by pat on 26/04/18.
//

#include "CreditGameState.hpp"

CreditGameState::CreditGameState(Game* game) {
    this->game = game;

    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
    this->view.setSize(pos);
    pos *= 0.5f;
    this->view.setCenter(pos);

    sf::Vector2f vel;
    sf::Vector2f acl = sf::Vector2f(0.0f, 0.0f);
    for( int i = 0; i < 5; i++ ) {
        vel = sf::Vector2f(rand() % 10, rand() % 10);
        pos = sf::Vector2f(rand() % (game->window.getSize().x - 50) + 10, rand() % (game->window.getSize().y - 50) + 10);
        bubbles.push_back(new Bubble(pos, vel, acl, STATE_SPLASHSCREEN, POP_ONE, this->game->textureManager.getRef("bubble")));
    }

	// heading
    title = sf::Text("Bubble Trouble Remastered\nCredits\n\n", this->game->primaryFont, 11);
    title.setCharacterSize(22);
    title.setPosition(10, 10);
	// contributors
	contributors = sf::Text("> Product Owner: Sarah Howarth\n> Lead Programmer: Patrick Kelley\n> Programmer: Jack Howarth-Green", this->game->primaryFont, 11);
	contributors.setCharacterSize(18);
	contributors.setPosition(10, 100);

	//back button
	MenuItem backButton;
	backButton.action = Back;

	backButton.rect.left = 30;
	backButton.rect.top = game->window.getSize().y - 25 - 30;
	backButton.rect.width = 100;
	backButton.rect.height = 25;

	backButton.buttonText = sf::Text("Back", this->game->secondaryFont, 12);
	backButton.buttonText.setPosition(sf::Vector2f(backButton.rect.left + 10, backButton.rect.top + 1));
	backButton.buttonText.setFillColor(sf::Color(0, 0, 0));

	backButton.button.setSize(sf::Vector2f(backButton.rect.width, backButton.rect.height));
	backButton.button.setPosition(sf::Vector2f(backButton.rect.left, backButton.rect.top));

	// Add buttons to list
	menuItems.push_back(backButton);
}

CreditGameState::~CreditGameState() {
    bubbles.clear();
}

void CreditGameState::handleEvents() {
    sf::Event event;

    while(this->game->window.pollEvent(event))
    {
        switch(event.type)
        {
            /* Close the window */
            case sf::Event::Closed:
            {
                this->game->window.close();
                this->game->end();
                break;
            }
            /* Resize the window */
            case sf::Event::Resized:
            {
                this->view.setSize(event.size.width, event.size.height);
                this->game->background.setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, 0)));
                this->game->background.setScale(
                        float(event.size.width) / float(this->game->background.getTexture()->getSize().x),
                        float(event.size.height) / float(this->game->background.getTexture()->getSize().y));
                break;
            }
            case sf::Event::KeyPressed:
            {
                if (event.key.code == sf::Keyboard::Escape) {
                    this->game->changeState(new MenuGameState(this->game));
                } else if (event.key.code == sf::Keyboard::Space) {
                    this->game->changeState(new MenuGameState(this->game));
                }
                break;
            }
			case sf::Event::MouseButtonReleased:
			{
				if (HandleClick(event.mouseButton.x, event.mouseButton.y) == Back) {
					game->changeState(new MenuGameState(this->game));
				}

				break;
			}
            default: break;

        }
    }
}

void CreditGameState::update(sf::Time delta) {
    for (auto &item : bubbles) {
        item->update(game->window, delta);
    }
}

void CreditGameState::draw(sf::Time delta) {
    this->game->window.setView(this->view);
    this->game->window.clear(sf::Color::Black);
    this->game->window.draw(this->game->background);

    for (auto &item : bubbles) {
        item->draw(this->game->window, delta);
    }

	for (auto &item : menuItems) {
		this->game->window.draw(item.button);
		this->game->window.draw(item.buttonText);
	}

    this->game->window.draw(title);
	this->game->window.draw(contributors);
}

CreditGameState::MenuResult CreditGameState::HandleClick(int x, int y)
{
	for (auto &item : menuItems) {
		if (y > item.rect.top && y < (item.rect.top + item.rect.height)) {
			return item.action;
		}
	}

	return Nothing;
}
