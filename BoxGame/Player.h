#pragma once
#include <SFML\Graphics.hpp>

class Player
{
public:
	Player();

	void update(float deltaTime);
	void draw(sf::RenderWindow& window);
	void onCollision();

	bool death_check() { return health > 0; }

private:
	sf::RectangleShape body;

	sf::Vector2f velocity;

	int health{ 100 };

	unsigned int row{ 0 };
	float speed{800.0f};
};

