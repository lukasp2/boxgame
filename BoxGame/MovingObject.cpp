#include "MovingObject.h"

MovingObject::MovingObject(Game& game, sf::Vector2f& velocity, sf::Vector2f& origin, sf::CircleShape& body,  float angle )
	: Entity { game }, body { body }, angle{ angle }
{
	Entity::velocity = velocity;

	MovingObject::body.setOrigin(body.getRadius(), body.getRadius());
	MovingObject::body.setPosition(origin);
	MovingObject::body.setRotation(angle);
}