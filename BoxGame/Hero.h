#pragma once
#include <SFML\Graphics.hpp>

#include "Projectile.h"

class Hero : public Drawable
{
public:
	~Hero() = default;
	Hero(sf::RenderWindow& window, sf::Color& color, int size, int speed, std::string name);

	void			update(float deltaTime);
	virtual void	update_more(float deltaTime) = 0;
	void			onCollision();
	virtual void	draw() = 0;

	// abilities
	virtual void	Q() = 0;
	virtual void	W() = 0;
	virtual void	E() = 0;
	virtual void	R() = 0;

	// upgrades
	virtual void	upgrade_Q() = 0;
	virtual void	upgrade_W() = 0;
	virtual void	upgrade_E() = 0;
	virtual void	upgrade_R() = 0;

	// setters & getters
	bool			death_check() { return health <= 0;			}
	sf::Vector2f	getPosition() { return body.getPosition();	}
	virtual std::string getName() { return "";					}

protected:
	std::vector<Projectile> projectiles;
	sf::Vector2f	velocity;			
	sf::Vector2f	seekPosition;
	sf::CircleShape body;
	sf::Text		hero_name;

	int				health;
	int				speed;
	int				level;
	int				XP;

	sf::Font& courier_font{ Font_Manager::load("Fonts/courier.ttf") };
};