#pragma once
#include "MovingObject.h"
#include <vector>

class Projectile : public MovingObject
{
public:
	Projectile(sf::RectangleShape body, float damage, sf::Vector2f velocity, float angle, sf::Vector2f origin)
		: MovingObject(body, velocity, angle, origin), damage{ damage } {}

	~Projectile() = default;

	bool update(float deltaTime, int range);

	bool isHit() const { return hasHit; };
	void setHit() { hasHit = true; };
	bool isDestroyed() const { return _isDestroyed; };

private:
	float damage{};
	bool hasHit{ false };
	bool _isDestroyed{ false };

	unsigned int deadTimer{ 0 };
	unsigned int liveTimer{ 0 };
};