#include "Projectile.h"
#include "Game.h"

Projectile::Projectile(Game& game, sf::Vector2f& velocity, sf::Vector2f& origin, sf::CircleShape& body, size_t damage, size_t range)
	: MovingObject{ game, velocity, origin, body}, damage{ damage }, range{ range }
{
	Entity::body.setFillColor(sf::Color::Transparent);
}

bool Projectile::update(float deltaTime)
{
	move(deltaTime);

	//implement lifetimer as clock instead
	lifeTimer++;

	return (lifeTimer > range || hit);
}
