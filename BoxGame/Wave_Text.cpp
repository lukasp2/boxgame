#include "Wave_Text.h"

Wave_Text::Wave_Text(Game& game, std::string wave)
	: Fading_Text{ game, wave, sf::Color(255,255,255,0), sf::Vector2f(150,-150), 18, 855, 600, 1, 1, 1 }
{
}