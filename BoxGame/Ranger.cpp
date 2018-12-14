#include "Ranger.h"
#include "Projectile.h"
#include "Hero.h"
#include <cmath>	// atan2

#define PI 3.14159265

Ranger::Ranger(Game & game, sf::Vector2f & position)
	: Enemy{ game, sf::Color::Red, 20.0f, 0.7f, 100, 5, "Ranger" }, // body color, size, speed, health, melee damage
	shoot_cooldown{ 1 }, 
	shoot_cooldown_clock{}, 
	static_proj{ 200, 10, 900, 4.0f, sf::Color::Red } // velocity, damage, range, radius, outline color
{							 
	body.setPosition(position);
	setInnerBodyPos();
}

void Ranger::update_more()
{
	if (shoot_cooldown <= shoot_cooldown_clock.getElapsedTime().asSeconds())
	{
		float delta_y = body.getPosition().y - game.player->getPosition().y;
		float delta_x = body.getPosition().x - game.player->getPosition().x;

		float radians = atan2(delta_y, delta_x);
		float degrees = static_cast<float>(180 / PI * radians);

		float x = -std::cos(radians);
		float y = -std::sin(radians);

		sf::Vector2f velocity{ static_proj.getVelocity() * x, static_proj.getVelocity() * y };
		sf::Vector2f origin{ body.getPosition().x + 2 * size * x, body.getPosition().y + 2 * size * y };

		Projectile p{ game, static_proj, velocity, origin, Projectile::type::hostile };

		game.add(std::make_shared<Projectile>(p));

		shoot_cooldown_clock.restart();
	}
}
