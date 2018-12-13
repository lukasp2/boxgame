#pragma once
#include <vector>
#include <memory>
#include "Menu.h"

class Highscore : public State
{
public:
	Highscore(sf::RenderWindow& window);
	
	virtual void process_input();
	virtual State* update();
	virtual void render();

private:
	struct Options
	{
		bool quit{ false };
		bool go_back{ false };
	};
	Options option;
	
	sf::Text header; //"highscore"
	sf::Text bottom; //"Press Enter to return"

	std::vector<sf::Text> scoreVector;

	std::unique_ptr<State> previous_state;
};

