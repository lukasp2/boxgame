#pragma once
#include "Bar.h"
#include "Character.h"

class Mini_Healthbar : public Bar
{
public:
	Mini_Healthbar(Game& game, Character& character, sf::Vector2f size, sf::Color color);

	bool update() override;
	void draw() override;

private:
	Character& character;
};


