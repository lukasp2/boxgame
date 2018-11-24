#include "Wall.h"

Wall::Wall(sf::RenderWindow& window, sf::RectangleShape body, sf::Vector2f size, sf::Vector2f position)
	: Drawable{ window }, body { body }
{
	body.setFillColor(sf::Color(190, 190, 190));
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setPosition(position);
}

void Wall::onCollision()
{
	//collision on left
	if (colDirection.x < 0.0f)		
		velocity.x = 0.0f;	
	
	//collision on right
	else if (colDirection.x > 0.0f)	
		velocity.x = 0.0f;	
	
	//collision below
	if (colDirection.y < 0.0f)		
		velocity.y = 0.0f;	
	
	//collision above
	else if (colDirection.y > 0.0f)	
		velocity.y = 0.0f;	
}