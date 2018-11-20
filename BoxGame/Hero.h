#pragma once
#include <SFML\Graphics.hpp>
#include "Resources.h" 

class Hero
{
public:
	Hero(sf::Color color, int size, int speed);
	~Hero() = default;

	void update(float deltaTime, sf::Window& window);
	void draw(sf::RenderWindow& window);
	void onCollision();
	bool death_check() { return health <= 0; }

	sf::Vector2f getPosition() { return body.getPosition(); }

	virtual void Q() = 0;
	virtual void W() = 0;
	virtual void E() = 0;
	virtual void R() = 0;

	virtual void upgrade_Q() = 0;
	virtual void upgrade_W() = 0;
	virtual void upgrade_E() = 0;
	virtual void upgrade_R() = 0;

	virtual std::string getName() = 0;

protected:
	sf::Vector2f velocity;
	sf::Vector2i seekPosition;
	sf::CircleShape body;
	int health{ 100 };
	int speed;

	sf::Font& courier_font{ Font_Manager::load("Fonts/courier.ttf") };
};

