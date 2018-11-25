#pragma once
#include "Drawable.h"
#include "Collider.h"
#include "Projectile.h"

class Character : public Drawable
{
public:
	Character(sf::RenderWindow& window, float size, int speed, int health, std::string name, sf::Color color);

	virtual void	draw();
	virtual void	update(float deltaTime) = 0;

	void			move_to(sf::Vector2f& go_Here);
	void			calculateOptimalMovement();
	bool			is_dead()			{ return health <= 0;	}

	sf::Vector2f&	getColDirection()	{ return colDirection;	}
	void			onCollision();
	Collider		getCollider()		{ return Collider{ body };	}

	sf::Vector2f	getPosition()				{ return body.getPosition(); }
	std::vector<Projectile>& getProjectiles()	{ return projectiles; }

	void			setHealth(int newHealth)	{ health = newHealth; }
	int				getHealth()					{ return health; }

protected:
	std::vector<Projectile> projectiles;
	
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