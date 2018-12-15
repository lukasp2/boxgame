#pragma once
#include <SFML/Graphics.hpp>

#include "Resources.h"
#include "Game.h"

class Entity
{
public:
	~Entity() = default;
	Entity(Game& game) : game{ game } {}

	virtual void	draw() = 0;
	virtual bool	update(float deltaTime) = 0;

	void			checkCollision(Entity& otherEntity);
	virtual void	onCollision(Entity& otherEntity) {};

	//ta bort, ha i character
	//sf::Vector2f	getPosition() { return body.getPosition(); }
	
	Game&			getGame() { return game; }

protected:
	Game& game;

	sf::CircleShape body;
};

