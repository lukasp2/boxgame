#include "Hero.h"

Hero::Hero(sf::RenderWindow& window_, sf::Color color, int size, int speed, std::string name) : window_{window_}, speed { speed }, level{}, XP{}
{
	body.setRadius(static_cast<float>(size));
	body.setFillColor(color);
	body.setOrigin(body.getRadius(), body.getRadius());
	body.setPosition(0, 0);

	hero_name.setFont(courier_font);
	hero_name.setCharacterSize(20);
	hero_name.setFillColor(sf::Color::Green);
	hero_name.setPosition(sf::Vector2f(-40, 300));
	hero_name.setString(name);
}

void Hero::update(float deltaTime)
{
	velocity.x *= 0.1f; //so the player doesn't
	velocity.y *= 0.1f; //accelerate away

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		seekPosition = sf::Vector2i(sf::Mouse::getPosition(window_).x - window_.getSize().x / 2, 
			sf::Mouse::getPosition(window_).y - window_.getSize().y / 2);
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

	update_more(deltaTime);
}

void Hero::onCollision()
{
}

