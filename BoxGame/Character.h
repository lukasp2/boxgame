#pragma once
#include <SFML/Graphics.hpp>

#include "Drawable.h"
#include "Collider.h"

class Character : public Drawable
{
public:
	Character(sf::RenderWindow& window, float size, int speed, int health, std::string name, sf::Color color);

	virtual void	draw() = 0;
	virtual void	update(float deltaTime) {};

	void			move_to(sf::Vector2f& go_Here);
	bool			death_check()		{ return health <= 0;			}
	sf::Vector2f	getPosition()		{ return body.getPosition();	}

	sf::Vector2f&	getColDirection()	{ return colDirection;		}
	Collider		getCollider()		{ return Collider{ body };	}
	void			onCollision();

protected:
	sf::Vector2f	colDirection;
	sf::Vector2f	velocity;

	sf::CircleShape body;
	float			size;
	int				health;
	int				speed;
	int				level;
	int				XP;
	sf::Text		name;

	// needed for inifinite directional movement
	sf::Vector2f	startPosition;
	sf::Vector2f	seekPosition;

private:
	sf::Font&		courier_font{ Font_Manager::load("Fonts/courier.ttf") };
};

