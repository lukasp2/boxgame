#include "Text.h"
#include "Hero.h"

Text::Text(Game& game, sf::Vector2f position, size_t size, std::string str, sf::Color color)
	: GUI_Object{ game }
{
	text.setFont(game.courier_font);
	text.setCharacterSize(size);
	text.setFillColor(color);
	text.setPosition(position);
	text.setString(str);
}