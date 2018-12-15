#pragma once
#include "Text.h"

class Kills_Text : public Text
{
public:
	Kills_Text(Game& game) : Text{ game, sf::Vector2f(-340, -410), 16, "kills: 0", sf::Color::White } {}

	bool update() override;
};

