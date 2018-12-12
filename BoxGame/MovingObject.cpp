#include "MovingObject.h"

MovingObject::MovingObject(Game& game, sf::Vector2f& velocity, sf::Vector2f& origin, sf::CircleShape& body,  float angle )
	: Entity { game }, body { body }, angle{ angle }, velocity {velocity}
{
	MovingObject::body.setOrigin(body.getRadius(), body.getRadius());
	MovingObject::body.setPosition(origin);
	MovingObject::body.setRotation(angle);
}

void MovingObject::onCollision()
{
	// collision on left
	if (colDirection.x < 0.0f)
	{
		velocity.x = 0.0f;
	}

	// collision on right
	else if (colDirection.x > 0.0f)
	{
		velocity.x = 0.0f;
	}

	// collision below
	if (colDirection.y < 0.0f)
	{
		velocity.y = 0.0f;
	}

	// collision above
	else if (colDirection.y > 0.0f)
	{
		velocity.y = 0.0f;
	}
}
