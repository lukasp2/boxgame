#pragma once
#include <memory>

#include "State.h"

class Controls : public State
{
public:
	Controls(sf::RenderWindow& window);

	virtual void process_input();
	virtual State* update();
	virtual void render();

private:
	sf::Event evnt;
	float VIEW_HEIGHT{ 1800.0f };
	sf::View menuView{ sf::Vector2f(900.0f, 800.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT) };

	struct Options
	{
		bool quit{ false };
	};
	Options option;

	sf::Text header; //"Controls"
	sf::Text bottom; //"Press Enter to return"

	std::vector<sf::Text> controlVector;
};

