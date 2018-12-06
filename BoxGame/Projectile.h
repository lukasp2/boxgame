#pragma once
#include "MovingObject.h"
#include "Game.h"

class Projectile : public MovingObject
{
public:
	~Projectile() = default;
	Projectile(Game& game, sf::Vector2f& velocity, sf::Vector2f& origin, sf::CircleShape& body, float degrees, size_t damage, size_t range);

	bool update (float deltaTime);
	void draw()	override { window.draw(body); }

	size_t getDamage()	{ return damage; }

private:
	size_t		damage;
	size_t		range;

	size_t		lifeTimer{};
	bool		hit{ false };
};