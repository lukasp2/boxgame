#include "Bar.h"

Bar::Bar(State& state, sf::Vector2f position, sf::Vector2f size, sf::Color color)
	: GUI_Object{ state }
{
	bar.setSize(size);
	bar.setPosition(position);
	bar.setFillColor(color);

	edge.setSize(size);
	edge.setPosition(position);
	edge.setFillColor(sf::Color::Transparent);
	edge.setOutlineColor(sf::Color::White);
	edge.setOutlineThickness(1.0f);
}

void Bar::draw()
{
	state.window.draw(bar);
	state.window.draw(edge);
}

void Bar::update()
{
	
}
