#pragma once
#include "Bar.h"

class Healthbar : public Bar
{
public:
	Healthbar(Game& game);

	bool update() override;
	void draw() override;

private:
	sf::Text healthtext;
};

