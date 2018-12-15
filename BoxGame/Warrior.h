#pragma once
#include "Enemy.h"

class Warrior : public Enemy
{
public:
	Warrior(Game& game, sf::Vector2f& position, int level);
private:
	size_t scale_damage(int level, size_t base_damage) override;
	float scale_health(int level, float base_health) override;
};