#include "Projectile.h"
#include "Enemy.h"
#include "Hero.h"
#include "Game.h"
#include "Damage_Text.h"
#include "GUI.h"

Projectile::Projectile(Game& game, Static_Projectile& proj, sf::Vector2f& velocity, sf::Vector2f& origin, enum type t)
	: MovingObject{ game, velocity }, damage{ proj.getDamage() }, range{ proj.getRange() }, t{ t }
{
	body = proj.getShape();
	body.setPosition(origin);
}

bool Projectile::update(float deltaTime)
{
	move(deltaTime);

	//implement lifetimer as clock instead?
	lifeTimer++;

	return (lifeTimer > range || hit);
}

void Projectile::onCollision(Entity& otherEntity)
{
	if (Enemy* e = dynamic_cast<Enemy*>(&otherEntity))
	{
		if (t == type::friendly && !hit)
		{
			e->damage_char(damage);
		}
		hit = true;
	}

	if (Hero* h = dynamic_cast<Hero*>(&otherEntity))
	{
		if (t == type::hostile && !hit)
		{
			h->damage_char(damage);
		}
		hit = true;
	}
}
