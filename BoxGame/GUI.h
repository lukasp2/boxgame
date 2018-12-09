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

	//denna klass är friendad i Hero

	void draw();
	void update();

protected:
	std::vector<std::unique_ptr<GUI_Object>> shapes;
	std::vector<sf::Text> texts;

	Game& game;
};