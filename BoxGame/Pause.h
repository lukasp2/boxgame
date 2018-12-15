#pragma once
#include "Menu.h"
#include "Game.h"

class Pause : public Menu
{
public:
	Pause(sf::RenderWindow& window, Game* ptr);

	void process_input() override;
	State* update() override;
	void render() override;

private:
	Game* ptr;

	struct Options
	{
		bool resume{ false };
		bool restart{ false };
		bool back_to_main{ false };
		bool quit{ false };
	};
	Options option;
};

