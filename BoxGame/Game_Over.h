#pragma once
#include "Menu.h"

class Game_Over : public Menu
{
public:
	Game_Over(sf::RenderWindow& window);

	void process_input() override;
	State* update() override;
	void render() override;

private:	
	sf::Clock clock;

	bool b{}; // fulhack för att fade:a långsammare ..

	struct Options
	{
		bool restart{ false };
		bool quit{ false };
		bool back_to_main{ false };
	};
	Options option;

};

