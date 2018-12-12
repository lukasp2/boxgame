#pragma once
#include "Bar.h"

class Mini_Healthbar : public Bar
{
public:
	Mini_Healthbar(Game& game, sf::Vector2f position, sf::Vector2f size, sf::Color color);

	bool update() override;
	void draw() override;

	int current_level;

private:
	sf::Text level_text;
	sf::RectangleShape level_box;
};


