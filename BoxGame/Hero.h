#pragma once
#include <SFML\Graphics.hpp>

#include "Projectile.h"
#include "Character.h"

class Hero : public Character
{
public:
	~Hero() = default;
	Hero(sf::RenderWindow& window, sf::Color color, float size, int speed, std::string name);

	void			update(float deltaTime);
	virtual void	update_more(float deltaTime) = 0;
	void			onCollision();
	virtual void	draw();

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
	virtual std::string getName() { return name;				}

protected:
	std::vector<Projectile> projectiles;
	sf::Vector2f	velocity;			
	sf::Vector2f	seekPosition;
	sf::Text		hero_name;

	sf::CircleShape body;
	std::string		name;
	float			size;
	int				health;
	int				speed;
	int				level;
	int				XP;

	sf::Font& courier_font{ Font_Manager::load("Fonts/courier.ttf") };
};