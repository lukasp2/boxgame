#pragma once

struct ability
{
	ability(int mana_cost, float cooldown, int level) : mana_cost{ mana_cost }, cooldown{ cooldown }, level{ level } {}
	int mana_cost;
	int level;
	float cooldown;
};

/*
struct shoot_ability : public ability
{
	shoot_ability(int mana_cost, size_t cooldown, float velocity, size_t damage, size_t range)
		: ability{ mana_cost, cooldown },
		velocity{ velocity },
		damage{ damage },
		range{ range }
	{}

	float velocity;
	size_t damage;
	size_t range;
	sf::CircleShape projectileShape;
};
*/