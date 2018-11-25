#include "Projectile.h"

void Projectile::update(float const deltaTime, std::vector<Projectile>& projectiles)
{
	for (auto pit = projectiles.begin(); pit != projectiles.end(); )
	{
		//pit->MovingObject::update(deltaTime);
		pit->body.move(velocity * deltaTime);

		if (pit->erase())
		{
			//pit = projectiles.erase(pit);
		}
		else
		{
		}
		pit++;
	}
	
	lifeTimer++;
}

bool Projectile::erase()
{
	return (lifeTimer > range || hit);
}

void Projectile::draw(std::vector<Projectile>& projectiles)
{
	for (Projectile& p : projectiles)
	{
		window.draw( p.body );
	}
}

void Projectile::checkCollision(std::vector<Projectile>& projectiles, std::vector<Enemy>& enemies)
{
	for (auto pit = projectiles.begin(); pit != projectiles.end(); ++pit )
	{
		for (Enemy& enemy : enemies)
		{
			if (enemy.getCollider().checkCollision(pit->body, enemy.getColDirection()))
			{
				enemy.setHealth( enemy.getHealth() - pit->getDamage() );
				pit->hit = true;
			}
		}
	}
}

void Projectile::checkCollision(std::vector<Projectile>& projectiles, Hero & player)
{
	for (auto pit = projectiles.begin(); pit != projectiles.end(); )
	{
		if (player.getCollider().checkCollision(pit->body, player.getColDirection()))
		{
			player.setHealth( player.getHealth() - pit->getDamage() );
			pit->hit = true;
		}
	}
}
