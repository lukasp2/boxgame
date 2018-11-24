#pragma once
#include <SFML/Graphics.hpp>

class Collider
{
public:
	Collider(sf::RectangleShape& body) : body{ body } {}
	~Collider() {}

	bool checkCollision(Collider& other, sf::Vector2f& direction);
	bool checkCollision(Collider& other, sf::Vector2f& direction, float push);

	sf::RectangleShape& body;

private:
	sf::Vector2f direction;
};

