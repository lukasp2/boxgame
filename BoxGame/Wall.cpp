#include "Wall.h"

Wall::Wall(Game& game, sf::RectangleShape b, sf::Vector2f size, sf::Vector2f position)
	: Entity{ game }, body{ b }
{
	body.setFillColor(sf::Color(190, 190, 190));
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setPosition(position);
}