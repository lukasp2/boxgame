#pragma once
#include "Fading_Text.h"

class Damage_Text : public Fading_Text // Fading_Text
{
public:
	Damage_Text(Game& game, std::string txt, sf::Color color, sf::Vector2f position) 
		: Fading_Text{ game, txt, color, position, 13, 400, 400-255, 0, 1, 255 } {}

	bool update() override;

};

