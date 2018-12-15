#include "Timed_Text.h"

Timed_Text::Timed_Text(Game& game, std::string txt, sf::Color color, sf::Vector2f position, size_t size, float lifelength)
	: Text{ game, position, size, txt, color }, lifelength{ lifelength }
{

}

bool Timed_Text::update()
{
	if ( lifelength < 255 && text.getFillColor().a != 0) //clock.getElapsedTime().asSeconds() 
	{
		sf::Color color{ text.getFillColor() };
		color.a -= 1;

		text.setFillColor(color);
	}
	
	return lifelength-- == 0; //clock.getElapsedTime().asSeconds() > lifelength;
}
