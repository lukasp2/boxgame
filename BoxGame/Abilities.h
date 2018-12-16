#pragma once

struct ability
{
	ability(int mana_cost, float cooldown, int level) : mana_cost{ mana_cost }, cooldown{ cooldown }, level{ level }, clock{} {}
	int mana_cost;
	int level;
	float cooldown;
	sf::Clock clock;
};