#pragma once
#include "Text.h"

class Waves : public Text
{
public:
	Waves(Game& game) 
		: Text{ game, sf::Vector2f(-150, -410), 16, "Wave: 1", sf::Color::White },
		current_wave{ 1 }, increment_wave{ false }, clock{} {}

	bool update() override;

private:
	bool increment_wave{};
	int current_wave{};
	Clock clock;
};

