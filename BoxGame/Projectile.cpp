#include "Projectile.h"
#include "Game.h"

Projectile::Projectile(Game& game, sf::Vector2f& velocity, sf::Vector2f& origin, sf::CircleShape& body, float degrees, size_t damage, size_t range)
	: MovingObject{ game, velocity, origin, body, degrees }, damage{ damage }, range{ range }
{
}

bool Projectile::update(float deltaTime)
{
	MovingObject::move(deltaTime);

	lifeTimer++;

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
