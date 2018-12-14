#pragma once
#include "Enemy.h"
class Ranger : public Enemy
{
public:
	Ranger(Game& game, sf::Vector2f& position);
	void update_more() override;

private:
	sf::Clock shoot_cooldown_clock;
	int shoot_cooldown;

	struct Projectile 
	{
		Projectile{} : velocity{ 500 }, damage{ 10 }, range{ 900 } {}
		
		sf::CircleShape shape;
		float velocity;
		size_t damage;
		size_t range;
	};
	Projectile projectile;
};

