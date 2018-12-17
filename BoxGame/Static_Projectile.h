#pragma once
#include <SFML/Graphics.hpp>

class Static_Projectile
{
public:
	Static_Projectile(float velocity, size_t damage, size_t range, float radius, sf::Color color);

	sf::CircleShape getShape()		{ return shape;		}
	size_t			getDamage()		{ return damage;	}
	size_t			getRange()		{ return range;		}
	float			getVelocity()	{ return velocity;	}

	void setDamage(size_t new_damage) { damage = new_damage; }

private:
	sf::CircleShape shape;
	size_t damage;
	size_t range;
	float velocity;
};


