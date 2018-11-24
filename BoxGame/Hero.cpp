#include "Hero.h"

#include <iostream>


Hero::Hero(sf::RenderWindow& window, sf::Color color, float size, int speed, std::string name) 
	: Drawable{ window }, speed{ speed }, size{ size }, level{}, XP{}, health{ 100 }
{
	// set hero body
	body.setRadius				(size);
	body.setFillColor			(sf::Color::Black);
	body.setOutlineColor		(color);
	body.setOutlineThickness	(2.0f);
	body.setOrigin				(body.getRadius(), body.getRadius());
	body.setPosition			(0, 0);

	// set hero name
	hero_name.setFont			(courier_font);
	hero_name.setCharacterSize	(20);
	hero_name.setFillColor		(sf::Color::Green);
	hero_name.setPosition		(sf::Vector2f(-40, 300));
	hero_name.setString			(name);
}

void Hero::update(float deltaTime)
{
	// so the player doesn't accelerate away
	velocity.x *= 0.1f; 
	velocity.y *= 0.1f; 

	// calculate target
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		float mouse_posx = sf::Mouse::getPosition(window).x - static_cast<float>(window.getSize().x / 2);
		float mouse_posy = sf::Mouse::getPosition(window).y - static_cast<float>(window.getSize().y / 2);

		seekPosition = sf::Vector2f(mouse_posx, mouse_posy);
	}

	// move hero to target
	if (getPosition().y > seekPosition.y)
	{
		velocity.y -= speed;
	}
	else if (getPosition().y < seekPosition.y)
	{
		velocity.y += speed;
	}
	if (getPosition().x > seekPosition.x)
	{
		velocity.x -= speed;
	}	
	else if (getPosition().x < seekPosition.x)
	{
		velocity.x += speed;
	}

	// target is close enough
	if (abs(getPosition().x - seekPosition.x) < 5)
	{
		velocity.x = 0;
	}
	if (abs(getPosition().y - seekPosition.y) < 5)
	{
		velocity.y = 0;
	}

	body.move(velocity * deltaTime);
	
	for (auto pit = projectiles.begin(); pit != projectiles.end(); )
	{
		// projectile is updated
		pit->update(deltaTime);

		// projectile is erased after collision or expired lifetime
		if (pit->erase())
		{
			pit = projectiles.erase(pit);
		}
		else
		{
			pit++;
		}
	}

	// specific for a certain hero
	update_more(deltaTime);
}

void Hero::draw()
{
	window.draw(body);

	for (Projectile& p : projectiles)
		p.draw();

	window.draw(hero_name);
}

void Hero::onCollision()
{
}

