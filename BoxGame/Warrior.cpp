#include "Warrior.h"
#include "Hero.h"

Warrior::Warrior(sf::RenderWindow& window) :
	// color, size, speed, health, damage, name
	Enemy{ window, sf::Color::Red, 20.0f, 100, 150, 10, "Saruman" }
{}

void Warrior::update(float deltaTime, sf::Vector2f playerPos)
{
	// so the player doesn't accelerate away
	velocity.x *= 0.1f;
	velocity.y *= 0.1f;

	float enemy_y = getPosition().y;
	float enemy_x = getPosition().x;

	float player_y = playerPos.y;
	float player_x = playerPos.x;

	// move hero to target
	if (enemy_y > player_y)
	{
		velocity.y -= speed;
	}
	else if (enemy_y < player_y)
	{
		velocity.y += speed;
	}
	if (enemy_x > player_x)
	{
		velocity.x -= speed;
	}
	else if (enemy_x < player_x)
	{
		velocity.x += speed;
	}

	// target is close enough
	if (abs(enemy_x - player_x) < 5)
	{
		velocity.x = 0;
	}
	if (abs(enemy_y - player_y) < 5)
	{
		velocity.y = 0;
	}

	body.move(velocity * deltaTime);
}

void Warrior::draw()
{
	window.draw(body);
	window.draw(name);
}
