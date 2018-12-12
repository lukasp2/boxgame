#include "Timed_Text.h"

Timed_Text::Timed_Text(Game& game, std::string txt, sf::Color color, sf::Vector2f position, size_t size, float lifelength)
	: GUI_Object{ game }, lifelength{ lifelength }
{
	sf::Text text;
	text.setString(txt);
	text.setCharacterSize(size);
	text.setPosition(position);
	text.setFillColor(color);
	text.setFont(game.courier_font);
}

void Timed_Text::draw()
{
	game.window.draw(text);
}

bool Timed_Text::update()
{
	return clock.getElapsedTime() > sf::Time(sf::seconds(lifelength));
}
