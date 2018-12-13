#pragma once
#include "Entity.h"
#include "Game.h"

class Character : public Entity
{
public:
	Character(Game& game, float size, int speed, double health, std::string name, sf::Color color);

	virtual bool	update(float deltaTime) = 0;
	void			move();
	virtual void	draw() override;
	virtual void	draw_more() {};

	// getters & setters
	sf::Vector2f	getPosition()				{ return body.getPosition(); }
	void			setInnerBodyPos();

	void			damage_char(int damage)		{ health -= damage; }
	double			getHealth()					{ return health; }
	double			getMaxHealth()				{ return max_health; }

protected:
	sf::Text		name;
	sf::CircleShape inner_body;

	float			size;
	double			health;
	double			max_health;
	int				speed;

	// needed for inifinite directional movement
	sf::Vector2f	startPosition;
	sf::Vector2f	seekPosition;
	int				x;
};