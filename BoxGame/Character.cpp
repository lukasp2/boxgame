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