#include "Ranger.h"
#include "Projectile.h"
#include "Hero.h"
#include <cmath>	// atan2

#define PI 3.14159265

Ranger::Ranger(Game & game, sf::Vector2f & position)
	: Enemy{ game, sf::Color::Red, 20.0f, 0.7f, 100, 5, "Ranger" },
							   // size, speed, health, melee damage
	shoot_cooldown{ 1 }, shoot_cooldown_clock{}, projectile{}
{							 
	body.setPosition(position); 
	setInnerBodyPos();

	projectile.shape.setOutlineColor(sf::Color::Red);
	projectile.shape.setFillColor(sf::Color::Black);
	projectile.shape.setOutlineThickness(1.0f);
	projectile.shape.setRadius(4.0f);
}

void Ranger::update_more()
{
	if (shoot_cooldown <= shoot_cooldown_clock.getElapsedTime().asSeconds())
	{
		float delta_y = body.getPosition().y + game.window.getSize().y / 2 - game.player->getPosition().y;
		float delta_x = body.getPosition().x + game.window.getSize().x / 2 - game.player->getPosition().x;

		float radians = atan2(delta_y, delta_x);
		float degrees = static_cast<float>(180 / PI * radians);

		float x = -std::cos(radians);
		float y = -std::sin(radians);

		sf::Vector2f velocity{ velocity * x, velocity * y };
		sf::Vector2f origin{ body.getPosition().x + 2 * size * x, body.getPosition().y + 2 * size * y };

		Projectile p{ game, velocity, origin, projectileShape, damage, range, Projectile::type::hostile };

		game.entities.push_back(std::make_unique<Projectile>(p));

		shoot_cooldown_clock.restart();
	}
}
