#pragma once
#include "Menu.h"

class Quit : public Menu
{
public:
	Quit();
	~Quit();

	virtual void process_input() {}
	virtual State* update() { return nullptr;  }
	virtual void render(sf::RenderWindow& window) {}

};

