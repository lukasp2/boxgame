#pragma once
#include "Enemy.h"

class Warrior : public Enemy
{
public:
	Warrior(Game& game, sf::Vector2f& position, int level);
};