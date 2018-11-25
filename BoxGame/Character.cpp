#include "Character.h"

Character::Character(sf::RenderWindow & window, float size, int speed, int health, std::string s_name, sf::Color color)
	: Drawable{ window }, size{ size }, speed{ speed }, XP{ 0 }
{
	// set cahracter body
	body.setRadius(size);
	body.setFillColor(sf::Color::Black);
	body.setOutlineColor(color);
	body.setOutlineThickness(2.0f);
	body.setOrigin(body.getRadius(), body.getRadius());
	body.setPosition(0, 0);

	// set character name
	name.setFont(courier_font);
	name.setCharacterSize(20);
	name.setFillColor(sf::Color::Green);
	name.setPosition(sf::Vector2f(-40, 300));
	name.setString(s_name);
}


void Character::onCollision()
{
	//collision on left
	if (colDirection.x < 0.0f)	
		velocity.x = 0.0f;	
	
	//collision on right
	else if (colDirection.x > 0.0f)	
		velocity.x = 0.0f;	
	
	//collsion on right
	if (colDirection.y < 0.0f) 
		velocity.y = 0.0f;	
	
	//collision below
	else if (colDirection.y > 0.0f)	
		velocity.y = 0.0f;	
}

void Character::move_to(sf::Vector2f& go_Here)
{
	if (getPosition().y > go_Here.y)
	{
		velocity.y -= speed;
	}
	else if (getPosition().y < go_Here.y)
	{
		velocity.y += speed;
	}
	if (getPosition().x > go_Here.x)
	{
		velocity.x -= speed;
	}
	else if (getPosition().x < go_Here.x)
	{
		velocity.x += speed;
	}
}

// This optimizes the characters movement, allowing it to move in
// infinite directions rather than the standard 8 directional movement.
void Character::calculateOptimalMovement()
{
	// just so the character doesn't accelerate
	velocity.x *= 0.1f;
	velocity.y *= 0.1f;

	// u: adjusted vector of current position 
	sf::Vector2f u{ body.getPosition().x - startPosition.x, body.getPosition().y - startPosition.y };
	// v: adjusted vector of seek position
	sf::Vector2f v{ seekPosition.x - startPosition.x, seekPosition.y - startPosition.y };

	// calculating dot product for the denominator and the numerator
	long double	dot_product_1{ (u.x * v.x) + (u.y * v.y) };
	long double	dot_product_2{ (v.x * v.x) + (v.y * v.y) };
	long double scalar{ dot_product_1 / dot_product_2 };

	sf::Vector2f unadjusted_result{ static_cast<float>(scalar * v.x) , static_cast<float>(scalar * v.y) };
	sf::Vector2f result{ unadjusted_result.x + startPosition.x , unadjusted_result.y + startPosition.y };

	// we now have the orthogonal projection of our point u on the vector v.
	// check distance between player and this projection ( result )
	size_t delta_x = static_cast<size_t>(abs(body.getPosition().x - result.x));
	size_t delta_y = static_cast<size_t>(abs(body.getPosition().y - result.y));

	long double distance = sqrt(pow(delta_x, 2) + pow(delta_y, 2));

	if (distance < 5)
	{
		move_to(seekPosition);
	}
	else
	{
		move_to(result);
	}

	// target is close enough
	if (abs(body.getPosition().x - seekPosition.x) < 5)
	{
		velocity.x = 0;
	}
	if (abs(body.getPosition().y - seekPosition.y) < 5)
	{
		velocity.y = 0;
	}
}

void Character::draw()
{
	window.draw(body);
	window.draw(name);
}