#pragma once
#include "Game.h"
#include "Entity.h"

class MovingObject : public Entity
{
public:
	~MovingObject() = default;
	MovingObject(Game& game, sf::Vector2f& velocity, sf::Vector2f& origin, sf::CircleShape& body);

	void			move(float deltaTime)			{ body.move(velocity * deltaTime); }
	virtual void	draw() = 0;
	void			onCollision() override;

	void			setPosition(sf::Vector2f pos)	{ body.setPosition(pos);	}
	sf::Vector2f	getPosition()					{ return body.getPosition();}

protected:
	sf::Vector2f	velocity;
	sf::Vector2f	colDirection;
};