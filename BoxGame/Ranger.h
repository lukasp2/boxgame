#pragma once
#include "Enemy.h"
#include "Static_Projectile.h"

class Ranger : public Enemy
{
public:
	Ranger(Game& game, sf::Vector2f& position, int level);
	void update_more() override;

private:
	size_t scale_damage(int level, size_t base_damage) override;
	float scale_health(int level, float base_health) override;

	sf::Clock shoot_cooldown_clock;
	int shoot_cooldown;

	Static_Projectile static_proj;
};

