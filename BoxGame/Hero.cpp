#include "Hero.h"
#include <cmath>
#include <iostream>

#define PI 3.14159265

Hero::Hero(sf::RenderWindow& window, sf::Color color, float size, int speed, std::string name) 
	: Character{ window, size, speed, 100, name, color }
{}

void Hero::update(float deltaTime)
{
	// so the player doesn't accelerate away
	velocity.x *= 0.1f; 
	velocity.y *= 0.1f; 

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
	{
		float mouse_posx = sf::Mouse::getPosition(window).x - static_cast<float>(window.getSize().x / 2);
		float mouse_posy = sf::Mouse::getPosition(window).y - static_cast<float>(window.getSize().y / 2);

		seekPosition = sf::Vector2f{ mouse_posx, mouse_posy };
		startPosition = sf::Vector2f{ body.getPosition().x, body.getPosition().y };
	}
	
	// u: adjusted vector of current position 
	sf::Vector2f u	{ body.getPosition().x - startPosition.x, body.getPosition().y - startPosition.y };
	// v: adjusted vector of seek position
	sf::Vector2f v	{ seekPosition.x - startPosition.x, seekPosition.y - startPosition.y };

	// calculating dot product for the denominator and the numerator
	long double	dot_product_1		{ (u.x * v.x) + (u.y * v.y) };
	long double	dot_product_2		{ (v.x * v.x) + (v.y * v.y) };
	long double scalar				{ dot_product_1 / dot_product_2 };

	sf::Vector2f unadjusted_result	{ static_cast<float>(scalar * v.x) , static_cast<float>(scalar * v.y) };
	sf::Vector2f result				{ unadjusted_result.x + startPosition.x , unadjusted_result.y + startPosition.y };

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
	
	body.move(velocity * deltaTime);
	
	for (auto pit = projectiles.begin(); pit != projectiles.end(); )
	{
		// projectile is updated
		pit->update(deltaTime);

		// projectile is erased after collision or expired lifetime
		if (pit->erase())
		{
			//pit = projectiles.erase(pit);
		}
		else
		{
		}
			pit++;
	}
}

void Hero::draw()
{
	window.draw(body);

	for (Projectile& p : projectiles)
		p.draw();

	window.draw(name);
}

