#include "Entity.h"
#include <iostream>

void Entity::checkCollision(Entity& otherEntity)
{
	float delta_x = abs(body.getPosition().x - otherEntity.body.getPosition().x );
	float delta_y = abs(body.getPosition().y - otherEntity.body.getPosition().y );

	float dist{ sqrt(delta_x * delta_x + delta_y * delta_y) };

	if (dist <= body.getRadius() + otherEntity.body.getRadius())
	{
		onCollision(otherEntity);
	}
}