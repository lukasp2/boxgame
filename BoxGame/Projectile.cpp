#include "Projectile.h"

void Projectile::update(float const deltaTime)
{
	MovingObject::update(deltaTime);

	lifeTimer++;
}

bool Projectile::erase()
{
	return (lifeTimer > range || hit);
}