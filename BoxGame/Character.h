#pragma once

#include "Entity.h"
#include "Game.h"
#include "Collider.h"

class Character : public Entity
{
public:
	Character(Game& game, float size, int speed, int health, std::string name, sf::Color color);

	virtual bool	update(float deltaTime) = 0;
	void			move();
	virtual void	draw() override;
	virtual void	draw_more() {};

	// getters & setters
	Collider		getCollider()				{ return Collider{ body };	}

	sf::Vector2f	getPosition()				{ return body.getPosition(); }

	void			setHealth(int newHealth)	{ health = newHealth; }
	int				getHealth()					{ return health; }

protected:
	sf::Text		name;
	sf::CircleShape body;
	float			size;
	int				health;
	int				speed;
	int				level;
	int				XP;

	// needed for inifinite directional movement
	sf::Vector2f	startPosition;
	sf::Vector2f	seekPosition;
	int				x;
};