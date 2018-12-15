#pragma once
#include "Text.h"
#include "Game.h"

class Timed_Text : public Text
{
public:
	Timed_Text(Game& game, std::string txt, sf::Color color, sf::Vector2f position, size_t size, float lifelength);

	bool update() override;

private:
	float lifelength;
};
