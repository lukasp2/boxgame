#pragma once
#include "Menu.h"

class Main_Menu : public Menu
{
public:
	Main_Menu(sf::RenderWindow& window);

	virtual void process_input() override;
	virtual State* update() override;
	virtual void render() override;

private:
	struct Options
	{
		bool start{ false };
		bool practice{ false };
		bool highscore{ false };
		bool controls{ false };
		bool quit{ false };
	};
	Options option;
};