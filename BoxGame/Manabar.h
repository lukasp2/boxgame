#pragma once
#include "Bar.h"

class Manabar : public Bar
{
public:
	Manabar(Game& game);
	
	bool update() override;
	void draw() override;

private:
	sf::Text manatext;
};

