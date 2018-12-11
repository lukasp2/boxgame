#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "Game.h"
#include "GUI_Object.h"
#include "Timed_Text.h"

class GUI
{
public:
	GUI(Game& game);
	~GUI() = default;

	void proccess_input(sf::Event event);
	void draw();
	void update();

protected:
	std::vector<std::unique_ptr<GUI_Object>> GUI_Objects;
	std::vector<sf::Text> texts;
	
	Game& game;
};