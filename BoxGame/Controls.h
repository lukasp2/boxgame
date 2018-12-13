#pragma once
#include <memory>

#include "State.h"

class Controls : public State
{
public:
	Controls(sf::RenderWindow& window);

	virtual void	process_input();
	virtual State*	update();
	virtual void	render();

private:
	struct Options
	{
		bool go_back{ false };
		bool quit{ false };
	};
	Options		option;

	sf::Text	header; //"Controls"
	sf::Text	bottom; //"Press Enter to return"

	std::vector<sf::Text> controlVector;
};

