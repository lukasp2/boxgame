#pragma once
#include "Enemy.h"

class Warrior : public Enemy
{
public:
	Warrior(Game& game, sf::Vector2f& position) : Enemy{ game, sf::Color::Red, 20.0f, 0.7f, 150, 10, "Warrior" } 
	{
		body.setPosition(position);
	}
												  // size, speed, health, damage
};