#include "Projectile.h"
#include "Hero.h"
#include "Enemy.h"
#include "Game.h"

//void Projectile::update(float const deltaTime, std::vector<Projectile>& projectiles)
void Projectile::update(float deltaTime)
{
	MovingObject::update(deltaTime);

	//check collision här?

	if (erase())
	{
		delete this;
		//pit = projectiles.erase(pit);
	}
	
	lifeTimer++;
}

bool Projectile::erase()
{
	return (lifeTimer > range || hit);
}


/*
void Projectile::checkCollision(std::vector<Projectile>& projectiles, std::vector<Enemy>& enemies)
{
	for (auto pit = projectiles.begin(); pit != projectiles.end(); ++pit )
	{
		for (auto eit = enemies.begin(); eit != enemies.end(); eit++ )
		{
			if (eit->getCollider().checkCollision(pit->body, eit->getColDirection()))
			{
				pit->hit = true;
				eit->got_damaged(pit->getDamage());
			}
			else
			{
				//eit = enemies.erase(eit);
			}
		}
	}
}

void Projectile::checkCollision(std::vector<Projectile>& projectiles, Hero& player)
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
*/
