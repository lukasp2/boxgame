#include "MovingObject.h"

MovingObject::MovingObject(Game& game, sf::Vector2f& velocity, sf::Vector2f& origin, sf::RectangleShape& _body,  float angle )
	: Entity { game }, body { _body }, angle{ angle }
{
	Entity::velocity = velocity;

	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(origin);
	body.setRotation(angle);
}