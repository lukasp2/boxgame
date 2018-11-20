#include "Hero.h"

Hero::Hero(sf::Color color, int size, int speed) : speed{ speed }
{
	body.setRadius(static_cast<float>(size));
	body.setFillColor(color);
	body.setOrigin(body.getRadius(), body.getRadius());
	body.setPosition(0, 0);
}

void Hero::update(float deltaTime, sf::Window& window)
{
	velocity.x *= 0.1f; //so the player doesn't
	velocity.y *= 0.1f; //accelerate away

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		seekPosition = sf::Vector2i(sf::Mouse::getPosition(window).x - window.getSize().x / 2, 
			sf::Mouse::getPosition(window).y - window.getSize().y / 2);
	}

	if (getPosition().y > seekPosition.y)
		velocity.y -= speed; 
	
	else if (getPosition().y < seekPosition.y)
		velocity.y += speed;

	if (getPosition().x > seekPosition.x)
		velocity.x -= speed;

	else if (getPosition().x < seekPosition.x)
		velocity.x += speed;

	if (abs(getPosition().x - seekPosition.x) < 5)
		velocity.x = 0;

	if (abs(getPosition().y - seekPosition.y) < 5)
		velocity.y = 0;

	body.move(velocity * deltaTime);
}

void Hero::draw(sf::RenderWindow & window)
{
	window.draw(body);	
	
	sf::Text hero_name;
	hero_name.setFont(courier_font);
	hero_name.setCharacterSize(20);
	hero_name.setFillColor(sf::Color::Green);
	hero_name.setPosition(sf::Vector2f(-40, 300));
	hero_name.setString(getName());
	window.draw(hero_name);
}

void Hero::onCollision()
{
}

