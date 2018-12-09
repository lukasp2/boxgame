#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "Game.h"
#include "GUI_Object.h"

class GUI
{
public:
	GUI(Game& game);
	~GUI() = default;

	void draw();
	void update();

	void upgrade_avalble();

	void upgrade_Q();
	void upgrade_W();
	void upgrade_E();
	void upgrade_R();

	void used_Q();
	void used_W();
	void used_E();
	void used_R();

protected:
	std::vector<std::unique_ptr<GUI_Object>> GUI_Objects;
	std::vector<sf::Text> texts;

	Game& game;
};