#pragma once
#include "Fading_Text.h"

#define TIME_ALIVE 855.0f

class Wave_Text : public Fading_Text
{
public:
	Wave_Text(Game& game, std::string wave) 
		: Fading_Text{ game, wave, sf::Color(255,255,255,0), sf::Vector2f(150,-150), 18, 855, 600, 1, 1, 1 } {}

	//bool update() override;
	//void draw() override;
};

