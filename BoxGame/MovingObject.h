#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>

#include "Collider.h"
#include "Drawable.h"

class MovingObject : public Drawable
{
public:
	~MovingObject() = default;
	MovingObject(sf::RenderWindow& window, sf::Vector2f& velocity, sf::Vector2f& origin, sf::RectangleShape& _body, float angle);

	void	onCollision();
	void	update(float deltaTime)	{ body.move(velocity * deltaTime); }
	void	draw() override			{ window.draw(body); }
	
	void			setPosition(sf::Vector2f pos)	{ body.setPosition(pos);	}
	sf::Vector2f	getPosition()					{ return body.getPosition();}
	sf::Vector2f &	getColDirection()				{ return colDirection;		}
	Collider		getCollider()					{ return Collider(body);	}

protected:
	sf::RectangleShape	body;
	sf::Vector2f		colDirection;
	sf::Vector2f		velocity;

private:
	float angle;
};