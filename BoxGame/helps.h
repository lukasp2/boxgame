#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"

sf::Text text_processor(int const & charSize, 
	std::string const & str, 
	sf::Color color, 
	sf::Vector2f pos, 
	std::string const & fontstr)
{
	sf::Text text;
	sf::Font& font{ Font_Manager::load(fontstr) };
	text.setFont(font);
	text.setCharacterSize(charSize);
	text.setString(str);
	text.setFillColor(color);
	text.setPosition(pos);

	return text;
}