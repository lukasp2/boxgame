#pragma once
#include "Enemy.h"
class Warrior : public Enemy
{
public:
	Warrior(sf::RenderWindow& window); //Warrior w (window);
	
	virtual void	update(float deltaTime, sf::Vector2f playerPos) override;
	virtual void	draw() override;
};

