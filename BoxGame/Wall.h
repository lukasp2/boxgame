#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Collider.h"
#include "Drawable.h"

class Wall : public Drawable
{
public:
	Wall(sf::RenderWindow& window, sf::RectangleShape body, sf::Vector2f size, sf::Vector2f position);

	void			onCollision();
	void			update()			{ body.move(velocity);	}
	void			draw() override		{ window.draw(body);	}

	Collider		getCollider()		{ return Collider(body);}
	sf::Vector2f&	getColDirection()	{ return colDirection;	}

private:
	sf::Vector2f		colDirection;
	sf::Vector2f		velocity;
	sf::RectangleShape	body;
};