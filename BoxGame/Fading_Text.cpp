#include "Fading_Text.h"

bool Fading_Text::update()
{
	if (clock.getElapsedTime().asSeconds() > show_text_at)
	{
		show_text = true;
	}

	if (show_text)
	{
		lifelength--;

		if (lifelength > total_life_length - 255 && text.getFillColor().a < 254)
		{
			sf::Color color{ text.getFillColor() };
			color.a += appear_speed;

			text.setFillColor(color);
		}
	}

	if (lifelength < 255 && text.getFillColor().a != 0)
	{
		sf::Color color{ text.getFillColor() };
		color.a -= dissappear_speed;

		text.setFillColor(color);
	}

	return lifelength == 0;
}

void Fading_Text::draw()
{
	if (show_text)
	{
		game.window.draw(text);
	}
}

