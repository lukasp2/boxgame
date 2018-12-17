#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "Game.h"
#include "GUI_Object.h"
#include "Timed_Text.h"
#include "Character.h"

class GUI
{
public:
	GUI(Game& game);
	~GUI() = default;

	void proccess_input(sf::Event event);
	void draw();
	void update();

	void add(std::unique_ptr<GUI_Object> p);
	void add(Character& character);

	int getWave() { return wave; }
	void incWave() { wave++; }

protected:
	std::vector<std::unique_ptr<GUI_Object>> GUI_Objects;	
	Game& game;
	int wave{ 1 };

private:
	Clock system_clock{};
};