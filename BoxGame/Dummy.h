#pragma once
#include "Enemy.h"
#include "Game.h"

class Dummy : public Enemy
{
public:
	Dummy(Game& game, sf::Vector2f& position);

	void damage_char(int damage);
	size_t scale_damage(int level, size_t base_damage) { return 0; };
	float scale_health(int level, float base_health) { return 0; };
};

