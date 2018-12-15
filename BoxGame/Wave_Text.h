#pragma once
#include "Timed_Text.h"

class Wave_Text : public Timed_Text
{
public:
	Wave_Text(Game& game, std::string& wave) : Timed_Text{ game, wave, sf::Color::White, sf::Vector2f(150,-150), 18, 855.0f } {}
};

