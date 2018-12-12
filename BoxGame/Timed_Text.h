#pragma once
#include "GUI_Object.h"
#include "Game.h"

class Timed_Text : public GUI_Object
{
public:
	Timed_Text(Game& game, std::string txt, sf::Color color, sf::Vector2f position, size_t size, float lifelength);

	void draw() override;
	bool update() override;

private:
	sf::Text text;
	sf::Clock clock;
	float lifelength;
};
