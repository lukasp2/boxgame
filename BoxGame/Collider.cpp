/*
sf::Vector2f getHalfSize(sf::Shape& shape)
{
	sf::Vector2f shapeHalfSize;

	if (sf::RectangleShape* s = dynamic_cast<sf::RectangleShape*>(&shape))
	{
		shapeHalfSize = s->getSize() / 2.0f;
	}
	else if (sf::CircleShape* s = dynamic_cast<sf::CircleShape*>(&shape))
	{
		shapeHalfSize = sf::Vector2f{ s->getRadius(), s->getRadius() };
	}

	return shapeHalfSize;
}

bool checkCollision(sf::Shape& other, sf::Vector2f& direction)
{
	float delta_x = other.getPosition().x - body.getPosition().x;
	float delta_y = other.getPosition().y - body.getPosition().y;

	sf::Vector2f ourSize = getHalfSize(body);
	sf::Vector2f theirSize = getHalfSize(other);

	float intersect_x = abs(delta_x - (theirSize.x + ourSize.x));
	float intersect_y = abs(delta_y - (theirSize.y + ourSize.y));

	// collision
	if (intersect_x < 0.0f && intersect_y < 0.0f) 
	{
		// collision on x-axis
		if (intersect_x > intersect_y) 
		{
			// direction to push to
			if (delta_x > 0.0f) 
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
		// collision on y-axis
		else 
		{ 
			if (delta_y > 0.0f)
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

bool Collider::checkCollision(Collider& other, sf::Vector2f& direction, float push)
{
	sf::Vector2f otherHalfSize = other.body.getSize() / 2.0f;
	sf::Vector2f thisHalfSize = body.getSize() / 2.0f;

	float delta_x = other.body.getPosition().x - body.getPosition().x;
	float delta_y = other.body.getPosition().y - body.getPosition().y;

	float intersectX = abs(delta_x) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(delta_y) - (otherHalfSize.y + thisHalfSize.y);

	// push is greatest value (push or 0.0f)
	push = std::min(std::max(push, 0.0f), 1.0f); 

	if (checkCollision(other, direction)) 
	{
		if (direction.x < 0.0f)
		{	
			//collision on left
			body.move(-intersectX * (1.0f - push), 0.0f);
			other.body.move(intersectX * push, 0.0f);
		}

		else if (direction.x > 0.0f)
		{	
			//collision on right
			body.move(intersectX * (1.0f - push), 0.0f);
			other.body.move(-intersectX * push, 0.0f);
		}

		if (direction.y < 0.0f)
		{	
			//collision below
			body.move(0.0f, -intersectY * (1.0f - push));
			other.body.move(0.0f, intersectY * push);
		}

		else if (direction.y > 0.0f)
		{	
			//collision above
			body.move(0.0f, intersectY * (1.0f - push));
			other.body.move(0.0f, -intersectY * push);
		}

		return true;
	}
	
	return false;
}
*/


