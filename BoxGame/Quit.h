#pragma once
#include "Menu.h"

class Quit : public Menu
{
public:
	Quit();
	~Quit();

	virtual void process_input(sf::RenderWindow& window) override {}
	virtual State* update(sf::RenderWindow& window) override { return nullptr;  }
	virtual void render(sf::RenderWindow& window) override {}

};

