#pragma once
#include "Menu.h"
class Main_Menu : public Menu
{
public:
	Main_Menu();

	virtual void process_input(sf::RenderWindow& window) override;
	virtual State* update(sf::RenderWindow& window) override;
	virtual void render(sf::RenderWindow& window) override;

private:
	struct Options
	{
		bool start{ false };
		bool quit{ false };
		bool highscore{ false };
		bool controls{ false };
	};
	Options option;
};

