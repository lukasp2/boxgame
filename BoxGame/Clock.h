#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"

class Clock : public sf::Clock
{
public:
	Clock();

	sf::Text get_as_text();

private:
	sf::Text text_clock;
	sf::Clock clock;
};

