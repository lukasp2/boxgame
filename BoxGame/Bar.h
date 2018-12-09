#pragma once
#include <SFML/Graphics.hpp>

#include "Game.h"
#include "GUI_Object.h"

class Bar : public GUI_Object
{
public:
	Bar(Game& game, sf::Vector2f position, sf::Vector2f size, sf::Color color);

	void draw() override;
	void update() override;

private:
	sf::RectangleShape bar;
	sf::RectangleShape edge;
};