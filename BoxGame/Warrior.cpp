#include "Warrior.h"

Warrior::Warrior(Game& game, sf::Vector2f& position, int level)
	: Enemy{ game, sf::Color::Red, 20.0f, 0.7f, 150, 10, "Warrior" }
{							 // size, speed, health, damage
	body.setPosition(position); 
	setInnerBodyPos();

	Character::level = level;
}
