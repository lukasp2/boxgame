#include "Timed_Text.h"

Timed_Text::Timed_Text(Game& game, std::string txt, sf::Color color, sf::Vector2f position, size_t size, float lifelength)
	: Text{ game, position, size, txt, color }, lifelength{ lifelength }
{
}

bool Timed_Text::update()
{
	return lifelength-- == 0;
}
