#pragma once
#include <SFML/Graphics.hpp>

#include "Resources.h"
#include "Game.h"

class Entity
{
public:
	~Entity() = default;
	Entity(Game& game) : game{ game } {}
	
	enum type { hero = 1, enemy, hero_projectile, enemy_projectile};

	virtual void	draw() = 0;
	virtual bool	update(float deltaTime) = 0;

	bool			checkCollision(Entity& otherBody);
	//sf::Vector2f&	getColDirection() { return colDirection; }
	virtual void	onCollision() {};

protected:
	Game& game;

	sf::CircleShape body;
};

