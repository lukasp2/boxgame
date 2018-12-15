#include "Warrior.h"

Warrior::Warrior(Game& game, sf::Vector2f& position, int level)
	: Enemy{ game, position, sf::Color::Red, level, 20.0f, 0.7f, scale_health(level, 150), scale_damage(level, 10), "Warrior" }
{													// size, speed, health, damage
}

size_t Warrior::scale_damage(int level, size_t base_damage)
{
	return base_damage * level;
}

float Warrior::scale_health(int level, float base_health)
{
	return base_health * level;
}
