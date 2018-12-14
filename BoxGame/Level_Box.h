#pragma once
#include "GUI_Object.h"
#include "Character.h"

class Level_Box : public GUI_Object
{
public:
	Level_Box(Game& game, Character& character);

	bool update() override;
	void draw() override;

	int current_level;

private:
	Character& character;

	sf::Text level_text;
	sf::RectangleShape level_box;
	sf::Color level_box_color;
};

