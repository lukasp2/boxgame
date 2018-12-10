#pragma once

struct ability
{
	ability() = default;
	ability(int mana_cost, size_t cooldown) : mana_cost{ mana_cost }, cooldown{ cooldown }, level{ 0 } {}
	int mana_cost;
	int level;
	size_t cooldown;
};

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