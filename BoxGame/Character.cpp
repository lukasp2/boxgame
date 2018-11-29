#include "Character.h"

Character::Character(sf::RenderWindow & window, float size, int speed, int health, std::string s_name, sf::Color color)
	: Drawable{ window }, size{ size }, speed{ speed }, XP{ 0 }, x{ 0 }
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

// Allowing a character to move in infinite directions
void Character::calculateOptimalMovement()
{
	float delta_x = abs(seekPosition.x - startPosition.x);
	float delta_y = abs(seekPosition.y - startPosition.y);

	float dist{ sqrt(delta_x * delta_x + delta_y * delta_y) };

	float n{ dist / speed };

	x++;
	
	float t = 1.0f;

	if (n > 0.001f)
		t = static_cast<float>(x) / n;
	
	if (x >= n)
		x = n;
	
	sf::Vector2f v{ t * (seekPosition.x - startPosition.x), t * (seekPosition.y - startPosition.y) };

	sf::Vector2f result = v + startPosition;

	body.setPosition(result);
}

void Character::draw()
{
	window.draw(body);
	window.draw(name);
	draw_more();
}