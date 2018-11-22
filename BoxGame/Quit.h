#pragma once
#include "Menu.h"

class Quit : public Menu
{
public:
	Quit(sf::RenderWindow& window) : Menu{ window } {}
	~Quit() = default;

	virtual void process_input() override {}
	virtual State* update() override { return nullptr; }
	virtual void render() override {}
};

