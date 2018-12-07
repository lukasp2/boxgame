#pragma once
#include <SFML/Graphics.hpp>

#include "Resources.h"
#include "Game.h"

class Entity
{
public:
	enum type { hero, enemy, wall, projectile };

	~Entity() = default;
	
	// Entities contains a reference to the state that its in, usually the gamestate. Changing to State& could
	// be a good idea if I want to display Entities in a menu lets say.
	Entity(Game& game) : game{ game }, window{ game.window } {}

	virtual void	draw() = 0;
	virtual bool	update(float deltaTime) = 0;

	sf::Vector2f&	getColDirection() { return colDirection; }
	void			onCollision();

protected:
	Game& game;

	//this reference is just for convenience (game.window => window), removing it would be wise..
	sf::RenderWindow& window;

	sf::Vector2f		velocity;
	sf::Vector2f		colDirection;
};

