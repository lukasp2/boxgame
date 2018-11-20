#include "MovingObject.h"

MovingObject::MovingObject(sf::RectangleShape body, sf::Vector2f velocity, float angle, sf::Vector2f position)
	: body{ body }, angle { angle }, velocity{ velocity }
{
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setRotation(angle);
}

void MovingObject::update(float deltaTime)
{
	body.move(velocity * deltaTime);
}

void MovingObject::OnCollision()
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



