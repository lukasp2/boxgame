#pragma once

#include "Entity.h"
#include "Game.h"
#include "Collider.h"

class Character : public Entity
{
public:
	Character(Game& game, float size, int speed, double health, std::string name, sf::Color color);

	virtual bool	update(float deltaTime) = 0;
	void			move();
	virtual void	draw() override;
	virtual void	draw_more() {};

	// getters & setters
	Collider		getCollider()				{ return Collider{ body };	}

	sf::Vector2f	getPosition()				{ return body.getPosition(); }

	void			damaged(int damage)			{ health -= damage; }
	double			getHealth()					{ return health; }

protected:
	sf::Text		name;
	
	sf::CircleShape body;
	sf::CircleShape outer_body;
	sf::CircleShape inner_body;

	float			size;
	double			health;
	int				speed;
	int				level;

	// needed for inifinite directional movement
	sf::Vector2f	startPosition;
	sf::Vector2f	seekPosition;
	int				x;
};