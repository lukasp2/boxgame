#pragma once
#include "Bar.h"

class Manabar : public Bar
{
public:
	Manabar(Game& game, sf::Vector2f position, sf::Vector2f size, sf::Color color);
	
	bool update() override;
	void draw() override;

private:
	sf::Text manatext;
};

