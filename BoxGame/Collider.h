#pragma once
#include <SFML/Graphics.hpp>

class Collider
{
public:
	Collider(sf::Shape& body) : body{ body } {}

	bool checkCollision(sf::Shape& other, sf::Vector2f& direction);
	//bool checkCollision(Collider& other, sf::Vector2f& direction, float push);

	sf::Shape& body;
};

