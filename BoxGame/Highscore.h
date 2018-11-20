#pragma once
#include <vector>
#include <memory>
#include "Menu.h"

class Highscore : public State
{
public:
	Highscore(State* previous_state);
	
	virtual void process_input(sf::RenderWindow& window);
	virtual State* update(sf::RenderWindow& window);
	virtual void render(sf::RenderWindow& window);

private:
	sf::Event evnt;
	float VIEW_HEIGHT{ 1800.0f };
	sf::View menuView{ sf::Vector2f(900.0f, 800.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT) };
	
	struct Options
	{
		bool quit{ false };
	};
	Options option;
	
	sf::Text header; //"highscore"
	sf::Text bottom; //"Press Enter to return"

	std::vector<sf::Text> scoreVector;

	std::unique_ptr<State> previous_state;
};

