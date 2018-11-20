#include "Collider.h"

bool Collider::CheckCollision(Collider & other, sf::Vector2f & direction)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	// if collision
	if (intersectX < 0.0f && intersectY < 0.0f) 
	{
		// if collision on X-axis
		if (intersectX > intersectY) 
		{
			// direction to push to
			if (deltaX > 0.0f) 
			{
				// colliding to the right
				direction.x = 1.0f; 
				direction.y = 0.0f;
			}
			else
			{
				// colliding to the left
				direction.x = -1.0f; 
				direction.y = 0.0f;
			}
		}
		// if collision on Y - axis
		else 
		{ 
			if (deltaY > 0.0f)
			{
				// colliding down
				direction.y = 1.0f; 
				direction.x = 0.0f;
			}
			else
			{
				// colliding up
				direction.y = -1.0f; 
				direction.x = 0.0f;
			}
		}
		return true;
	}
	return false;
}

bool Collider::CheckCollision(Collider& other, sf::Vector2f& direction, float push)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	// push is greatest value (push or 0.0f)
	push = std::min(std::max(push, 0.0f), 1.0f); 

	if (CheckCollision(other, direction)) {

		if (direction.x < 0.0f)
		{	
			//collision on left
			Move(-intersectX * (1.0f - push), 0.0f);
			other.Move(intersectX * push, 0.0f);
		}

		else if (direction.x > 0.0f)
		{	
			//collision on right
			Move(intersectX * (1.0f - push), 0.0f);
			other.Move(-intersectX * push, 0.0f);
		}

		if (direction.y < 0.0f)
		{	//collision below
			Move(0.0f, -intersectY * (1.0f - push));
			other.Move(0.0f, intersectY * push);
		}

		else if (direction.y > 0.0f)
		{	//collision above
			Move(0.0f, intersectY * (1.0f - push));
			other.Move(0.0f, -intersectY * push);
		}

		return true;
	}
	
	return false;
}


