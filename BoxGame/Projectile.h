#pragma once
#include <vector>

#include "MovingObject.h"

class Projectile : public MovingObject
{
public:
	~Projectile() = default;
	Projectile(sf::RenderWindow& window, sf::Vector2f& velocity, sf::Vector2f& origin, sf::RectangleShape& body, float degrees, size_t damage, size_t range)
		: MovingObject{ window, velocity, origin, body, degrees}, damage{ damage }, range{ range } { }

	void update(float const deltaTime);
	bool erase();

private:
	size_t		 damage;
	size_t		 range;

	size_t		 lifeTimer{};
	bool		 hit{ false };
};