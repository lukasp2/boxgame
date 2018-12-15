#include "Wave_Text.h"
/*
bool Wave_Text::update()
{
	if (clock.getElapsedTime().asSeconds() > 1)
	{
		show_text = true;
	}

	if (show_text)
	{
		lifelength--;

		if (lifelength > TIME_ALIVE - 255 && text.getFillColor().a < 254)
		{
			sf::Color color{ text.getFillColor() };
			color.a += 1;

			text.setFillColor(color);
		}
	}
		
	if (lifelength < 255 && text.getFillColor().a != 0) //&& clock.getElapsedTime().asSeconds() > 0.01; clock.restart();
	{
		sf::Color color{ text.getFillColor() };
		color.a -= 1;

		text.setFillColor(color);
	}

	return lifelength == 0;
}

void Wave_Text::draw()
{
	if (show_text)
	{
		game.window.draw(text);
	}
}
*/
