#pragma once
#include "Text.h"

class Score_Text : public Text
{
public:
	Score_Text(Game& game) 
		: Text{ game, sf::Vector2f(100, -410), 16, "score: 0", sf::Color::White } {}

	bool update() override;
};