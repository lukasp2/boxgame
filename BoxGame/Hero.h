#pragma once
#include <SFML\Graphics.hpp>
#include "Resources.h" 
#include "Projectile.h"

class Hero
{
public:
	Hero(sf::RenderWindow& window_, sf::Color color, int size, int speed, std::string);
	~Hero() = default;

	void update(float deltaTime);
	virtual void update_more(float deltaTime) = 0;

	bool death_check() { return health <= 0; }
	
	void onCollision();
	virtual void draw() = 0;

	sf::Vector2f getPosition() { return body.getPosition(); }

	virtual void Q() = 0;
	virtual void W() = 0;
	virtual void E() = 0;
	virtual void R() = 0;

	virtual void upgrade_Q() = 0;
	virtual void upgrade_W() = 0;
	virtual void upgrade_E() = 0;
	virtual void upgrade_R() = 0;

	virtual std::string getName() { return ""; }

	sf::RenderWindow& window_;
protected:

	sf::Vector2f velocity;
	sf::Vector2i seekPosition;
	sf::CircleShape body;
	sf::Text hero_name;

	int health{ 100 };
	int speed;
	int level{ 0 };
	int XP{ 0 };

	sf::Font& courier_font{ Font_Manager::load("Fonts/courier.ttf") };
};

