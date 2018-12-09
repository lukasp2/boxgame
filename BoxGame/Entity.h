#pragma once
#include <SFML/Graphics.hpp>

#include "Resources.h"
#include "Game.h"

class Entity
{
public:
	enum type { hero, enemy, wall, projectile };

	~Entity() = default;

	Entity(Game& game) : game{ game } {}

	virtual void	draw() = 0;
	virtual bool	update(float deltaTime) = 0;

	sf::Vector2f&	getColDirection() { return colDirection; }
	void			onCollision();

protected:
	Game& game;

	//this reference is just for convenience (game.window => window), removing it would be wise..
	//sf::RenderWindow& window;

	sf::Vector2f		velocity;
	sf::Vector2f		colDirection;
};

