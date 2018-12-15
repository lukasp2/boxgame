#pragma once
#include "GUI_Object.h"

class Text : public GUI_Object
{
public:
	Text(Game& game, sf::Vector2f position, size_t size, std::string str, sf::Color color);

	virtual void draw() { game.window.draw(text); }
	virtual bool update() { return 0; }

protected:
	sf::Text text;
};