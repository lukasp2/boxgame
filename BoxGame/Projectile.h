#pragma once
#include <vector>

#include "MovingObject.h"

class Game;
class Enemy;
class Hero;

class Projectile : public MovingObject
{
public:
	~Projectile() = default;
	Projectile(Game& game) : MovingObject{ game } {}
	Projectile(Game& game, sf::Vector2f& velocity, sf::Vector2f& origin, sf::RectangleShape& body, float degrees, size_t damage, size_t range)
		: MovingObject{ game, velocity, origin, body, degrees}, damage{ damage }, range{ range } { }

	void update (float deltaTime);
	bool erase ();
	void draw()	override { window.draw(body); }

	//void checkCollision	(std::vector<Projectile>& projectiles, std::vector<Enemy>& enemies);
	//void checkCollision	(std::vector<Projectile>& projectiles, Hero& player);

	size_t getDamage()	{ return damage; }

private:
	size_t		damage;
	size_t		range;

	size_t		lifeTimer{};
	bool		hit{ false };
};