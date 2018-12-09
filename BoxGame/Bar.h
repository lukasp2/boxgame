#pragma once
#include <SFML/Graphics.hpp>

#include "State.h"
#include "GUI_Object.h"

class Bar : public GUI_Object
{
public:
	Bar(State& state, sf::Vector2f position, sf::Vector2f size, sf::Color color);
	~Bar() = default;

	void draw() override;
	void update() override;

private:
	sf::RectangleShape bar;
	sf::RectangleShape edge;
};

