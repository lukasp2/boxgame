#pragma once
#include "Game.h"
#include "Entity.h"

class MovingObject : public Entity
{
public:
	~MovingObject() = default;
	MovingObject(Game& game, sf::Vector2f& velocity);

	void			move(float deltaTime) { body.move(velocity * deltaTime); }
	virtual void	draw() = 0;
	virtual void	onCollision(Entity& otherBody) = 0;

protected:
	sf::Vector2f	velocity;
	sf::Vector2f	colDirection;
};