#include "Entity.h"
#include <iostream>

void Entity::checkCollision(Entity& otherEntity)
{
	// 100 is used because the number is larger than the size of any entity

	float delta_x{ body.getPosition().x - otherEntity.body.getPosition().x };
	
	if ( -100 < delta_x && delta_x < 100 )
	{
		float delta_y{ body.getPosition().y - otherEntity.body.getPosition().y };

		if (-100 < delta_y && delta_y < 100)
		{
			float dist{ sqrt(delta_x * delta_x + delta_y * delta_y) };

			if (dist <= body.getRadius() + otherEntity.body.getRadius())
			{
				onCollision(otherEntity);
			}
		}
	}
	
	/* slower, but more general, version:
	float delta_x{ abs(body.getPosition().x - otherEntity.body.getPosition().x) };
	float delta_y{ abs(body.getPosition().y - otherEntity.body.getPosition().y) };

	float dist{ sqrt(delta_x * delta_x + delta_y * delta_y) };

	if (dist <= body.getRadius() + otherEntity.body.getRadius())
	{
		onCollision(otherEntity);
	}
	*/
	
}