#pragma once
#include <vector>

#include "MovingObject.h"

class Enemy;
class Hero;

class Projectile : public MovingObject
{
public:
	~Projectile() = default;
	Projectile(sf::RenderWindow& window) : MovingObject{ window } {}
	Projectile(sf::RenderWindow& window, sf::Vector2f& velocity, sf::Vector2f& origin, sf::RectangleShape& body, float degrees, size_t damage, size_t range)
		: MovingObject{ window, velocity, origin, body, degrees}, damage{ damage }, range{ range } { }

	void update			(float const deltaTime, std::vector<Projectile>& projectiles);
	bool erase			();
	void draw			(std::vector<Projectile>& projectiles);
	void checkCollision	(std::vector<Projectile>& projectiles, std::vector<Enemy>& enemies);
	void checkCollision	(std::vector<Projectile>& projectiles, Hero& player);

	size_t getDamage()	{ return damage; }

private:
	size_t		damage;
	size_t		range;

	size_t		lifeTimer{};
	bool		hit{ false };
};