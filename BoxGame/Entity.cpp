#include "Entity.h"

void Entity::onCollision()
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