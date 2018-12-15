#pragma once
#include "Timed_Text.h"

#define TIME_ALIVE 855.0f

class Wave_Text : public Timed_Text
{
public:
	Wave_Text(Game& game, std::string wave) 
		: Timed_Text{ game, wave, sf::Color(255,255,255,0), sf::Vector2f(150,-150), 18, TIME_ALIVE }, clock{} {}

	bool update() override;
	void draw() override;

private:
	sf::Clock clock;
	bool show_text{ false };
};

