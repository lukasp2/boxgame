#pragma once

#include "Game.h"
#include "Entity.h"
#include "Collider.h"

class MovingObject : public Entity
{
public:
	~MovingObject() = default;
	MovingObject(Game& game) : Entity{ game } {}
	MovingObject(Game& game, sf::Vector2f& velocity, sf::Vector2f& origin, sf::RectangleShape& _body, float angle);

	void onCollision();
	void update(float deltaTime)					{ body.move(velocity * deltaTime); }
	virtual void draw() = 0;
	
	void			setPosition(sf::Vector2f pos)	{ body.setPosition(pos);	}
	sf::Vector2f	getPosition()					{ return body.getPosition();}
	sf::Vector2f&	getColDirection()				{ return colDirection;		}
	Collider		getCollider()					{ return Collider(body);	}

protected:
	sf::RectangleShape	body;
	sf::Vector2f		colDirection;
	sf::Vector2f		velocity;

private:
	float angle;
};