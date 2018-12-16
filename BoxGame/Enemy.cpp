#include "Enemy.h"
#include "Hero.h"
#include "Projectile.h"

#include "GUI.h"
#include "Damage_Text.h"
#include "Disappearing_Character.h"

#include <iostream>

Enemy::Enemy(Game& game, sf::Vector2f& position, sf::Color color, int level, float size, float speed, float health, size_t damage, std::string name)
	: Character{ game, size, speed, health, level, name, color },
	damage{ damage },
	melee_cooldown_clock{ },
	melee_cooldown{ 1 }
{
	// use a function setPosition which also sets InnerBodyPos
	body.setPosition(position);
	setInnerBodyPos();
}

void Enemy::damage_char(int damage)
{
	health -= damage;
	game.user_interface->add(std::make_unique<Damage_Text>(game, std::to_string(damage), sf::Color::White, body.getPosition()));
}

bool Enemy::update(float deltaTime)
{

	if (game.player->changed_movement)
	{
		startPosition = body.getPosition();
		x = 0;
	}

	// enemy avoid projectiles
	avoid_projectile = false;
	for (auto&& e : game.getEntities())
	{
		if (Projectile* p = dynamic_cast<Projectile*>(&(*e)))
		{
			if (p->getType() == Projectile::type::friendly)
			{
				// vector of projectile, the direction its moving
				sf::Vector2f v{ p->getVelocity() };

				// vector between projectile position and enemy position
				sf::Vector2f pe{ getPosition().x - p->getPosition().x, getPosition().y - p->getPosition().y};
				
				// scalar for pe projected onto v
				float nominator = pe.x * v.x + pe.y * v.y;
				float denominator = v.x * v.x + v.y * v.y;
				float scalar = nominator / denominator;

				// if the projectile is moving towards enemy
				if (scalar > 0)
				{
					// the vector of enemy position projected onto the projectile path
					sf::Vector2f pe_projected{ v.x * scalar, v.y * scalar };

					// the vector between enemy position and projectile path
					sf::Vector2f ev{ pe.x - pe_projected.x, pe.y - pe_projected.y };

					// the length between enemy position and projectile path
					float distance{ sqrt( ev.x * ev.x + ev.y * ev.y ) };
					
					if (distance / 2 <= getRadius())
					{
						avoid_projectile = true;

						// if we aimed precisely on target center, ev is (0, 0),
						// and an exception has to be made.
						if (distance < 8)
						{
							ev.x += v.y;
							ev.y += -v.x;
						}

						// move enemy away from projectile path
						seekPosition = sf::Vector2f{ getPosition().x + ev.x, getPosition().y + ev.y };
					}
				}
			}
		}
	}
	
	// moves enemy towards player
	if (!avoid_projectile)
	{
		seekPosition = game.player->getPosition();
	}
	Character::move();

	update_more();
	
	if (health <= 0)
	{
		game.player->on_kill(*this);
		game.add( std::make_shared<Disappearing_Character>(game, body, body.getOutlineColor(), 40));
	}
	
	return health <= 0;
}

void Enemy::draw_more()
{
}

void Enemy::onCollision(Entity& otherEntity)
{

}

size_t Enemy::melee_attack()
{
	if (melee_cooldown <= melee_cooldown_clock.getElapsedTime().asSeconds())
	{
		melee_cooldown_clock.restart();
		return damage;
	}

	return 0;
}
