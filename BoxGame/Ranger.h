#pragma once
#include "Enemy.h"
#include "Static_Projectile.h"

class Ranger : public Enemy
{
public:
	Ranger(Game& game, sf::Vector2f& position, int level);
	void update_more() override;

private:
	sf::Clock shoot_cooldown_clock;
	int shoot_cooldown;

	Static_Projectile static_proj;
};

