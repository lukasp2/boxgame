#include "Projectile.h"

bool Projectile::update(float deltaTime, int range)
{
	if (liveTimer > range || deadTimer >= 30)
	{
		return true;
	}

	if (!hasHit)
	{
		MovingObject::update(deltaTime);
		liveTimer++;

		return false;
	}

	deadTimer++;

	return false;
}

