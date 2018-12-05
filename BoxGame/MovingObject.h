#pragma once

#include "Game.h"
#include "Entity.h"
#include "Collider.h"

class MovingObject : public Entity
{
public:
	~MovingObject() = default;
	MovingObject(Game& game, sf::Vector2f& velocity, sf::Vector2f& origin, sf::RectangleShape& _body, float angle);

	void move(float deltaTime)	{ body.move(velocity * deltaTime); }
	virtual void draw() = 0;
	
	void			setPosition(sf::Vector2f pos)	{ body.setPosition(pos);	}
	sf::Vector2f	getPosition()					{ return body.getPosition();}
	Collider		getCollider()					{ return Collider(body);	}

protected:
	sf::RectangleShape	body;
	float angle;
};