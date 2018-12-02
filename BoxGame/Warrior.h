#pragma once
#include "Enemy.h"

class Warrior : public Enemy
{
public:
	Warrior(Game& game) : Enemy{ game, sf::Color::Red, 20.0f, 1, 150, 10, "Warrior" } {}
												  // size, speed, health, damage	
};