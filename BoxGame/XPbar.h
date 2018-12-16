#pragma once
#include "Bar.h"

class XPbar : public Bar
{
public:
	XPbar(Game& game) : Bar{game, sf::Vector2f(-200, 375), sf::Vector2f(400, 2), sf::Color(255, 255, 0, 255) } {}

	bool update() override;
};

