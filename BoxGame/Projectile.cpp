#include "Projectile.h"
#include "Enemy.h"
#include "Game.h"

Projectile::Projectile(Game& game, sf::Vector2f& velocity, sf::Vector2f& origin, sf::CircleShape& body, size_t damage, size_t range, enum type t)
	: MovingObject{ game, velocity }, damage{ damage }, range{ range }, t{ t }
{
	Entity::body = body;
	Entity::body.setOrigin(body.getRadius(), body.getRadius());
	Entity::body.setPosition(origin);
	Entity::body.setFillColor(sf::Color::Transparent);
}

bool Projectile::update(float deltaTime)
{
	move(deltaTime);

	//implement lifetimer as clock instead
	lifeTimer++;

	return (lifeTimer > range || hit);
}

void Projectile::onCollision(Entity& otherEntity)
{
	if (Enemy* e = dynamic_cast<Enemy*>(&otherEntity))
	{
		if (t == type::friendly)
		{
			e->damage_enemy(damage);
		}
	}

	hit = true;

	/*
	// collision on left
	if (colDirection.x < 0.0f)
	{
		velocity.x = 0.0f;
	}

	// collision on right
	else if (colDirection.x > 0.0f)
	{
		velocity.x = 0.0f;
	}

	// collision below
	if (colDirection.y < 0.0f)
	{
		velocity.y = 0.0f;
	}

	// collision above
	else if (colDirection.y > 0.0f)
	{
		velocity.y = 0.0f;
	}
	*/
}
